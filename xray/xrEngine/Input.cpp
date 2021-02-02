#include "stdafx.h"
#include "xr_input.h"

#include <gainput/gainput.h>

#if defined(_WIN32)
#	define WIN32_LEAN_AND_MEAN
#	define NOMINMAX
#	include <Windows.h>
#endif

#include "IInputReceiver.h"

CInput* pInput = NULL;

ENGINE_API float	psMouseSens = 1.f;
ENGINE_API float	psMouseSensScale = 1.f;
ENGINE_API Flags32	psMouseInvert = { FALSE };


static uint32_t dxKeyCode[256] = {
};

static uint32_t gaKeyCode[256] =
{
};

enum
{
	MouseX,
	MouseY,
	MouseWheel
};

inline bool CInput::AnyReceiver()
{
	return !receivers.empty();
}

CInput::CInput(bool bCaptureInput) : receivers()
{
	mouseDelta.set(0, 0);

	inputManager = new gainput::InputManager(false);

	keyboard = inputManager->CreateAndGetDevice<gainput::InputDeviceKeyboard>();
	mouse = inputManager->CreateAndGetDevice<gainput::InputDeviceMouse>();
	gamepad = inputManager->CreateAndGetDevice<gainput::InputDevicePad>();

	//keyboardId = keyboard->GetDeviceId();
	const gainput::DeviceId mouseId = mouse->GetDeviceId();
	//gamepadId = gamepad->GetDeviceId();

	inputMap = new gainput::InputMap(*inputManager);
	inputMap->MapFloat(MouseX, mouseId, gainput::MouseAxisX);
	inputMap->MapFloat(MouseY, mouseId, gainput::MouseAxisY);
	inputMap->MapFloat(MouseWheel, mouseId, gainput::MouseButtonWheelDown);

	const gainput::InputState* mouseCheckState = mouse->GetInputState();
	const u8 mouseInputsCount = (u8)mouseCheckState->GetButtonCount();

	for (u8 i = 0; i < mouseInputsCount; i++)
	{
		if (!mouse->IsValidButtonId(i) || mouse->GetButtonType(i) != gainput::BT_BOOL)
			continue;

		mouseButtons.push_back(i);
	}

	//#OPTIMIZE @Scht: remove all unbound buttons 
	//	get device input on binding instead of OnFrame

#ifdef ENGINE_BUILD
	Device.seqAppActivate.Add(this);
	Device.seqAppDeactivate.Add(this, REG_PRIORITY_HIGH);
	Device.seqFrame.Add(this, REG_PRIORITY_HIGH);
#endif
}

void CInput::OnWindowResize(int width, int height)
{
	inputManager->SetDisplaySize(width, height);
}

void CInput::OnAppDeactivate()
{
	if (CurrentIR())
		CurrentIR()->IR_OnDeactivate();
}

void CInput::OnAppActivate()
{
	if (CurrentIR())
		CurrentIR()->IR_OnActivate();
}

IInputReceiver* CInput::CurrentIR()
{
	if (!receivers.empty())
	{
		return receivers.back();
	}
	return nullptr;
}

int CInput::iGetAsyncKeyState(int dik)
{
	return keyboard->GetInputState()->GetBool(dik + 1);
}

void CInput::iGetLastMouseDelta(Ivector2& p)
{
	// @ Does this really used?
	p.set((int)Device.dwWidth*mouseDelta.x, Device.dwHeight*mouseDelta.y);
}

int CInput::iGetAsyncBtnState(int btn)
{
	return mouse->GetInputState()->GetBool(btn);
}

bool CInput::get_dik_name(int dik, LPSTR dest_str, int dest_sz)
{
	return false;
}

void CInput::OnFrame()
{
	inputManager->Update(Device.dwTimeDelta);

	if (gamepad->IsAvailable())
	{
		UpdateGamepad();
	}

	// @ Scht. -> Anton: 
	// gamepad update is mandatory 'cause we can vibrate for some time at this point
	// and we may want to disable vibration in time even if there is no receiver

	if (!AnyReceiver())	return;

	gainput::InputState* mouse_state = mouse->GetInputState();
	gainput::InputState* prev_state = mouse->GetPreviousInputState();

	for (const auto& idx : mouseButtons)
	{
		if (!AnyReceiver())	return;

		bool prevState = prev_state->GetBool(idx);
		bool currState = mouse_state->GetBool(idx);

		const int translatedButtonId = idx < 2 ? idx : idx + 100;

		// holding: was true and now true
		if (prevState && currState)
		{
			receivers.back()->IR_OnMouseHold(translatedButtonId);
			continue;
		}

		// press: was false and now true
		if (!prevState && currState)
		{
			receivers.back()->IR_OnMousePress(translatedButtonId);
			continue;
		}

		// released: was true and now false
		if (prevState && !currState)
		{
			receivers.back()->IR_OnMouseRelease(translatedButtonId);
			continue;
		}
	}

	constexpr float eps = std::numeric_limits<float>::epsilon();

	static float pdX = 0;
	static float pdY = 0;

	// WHAT THE FUCK?!
	// It seems like UI just ignores those factors but scene doesn't
	// 
	const float dX = Device.dwWidth * inputMap->GetFloatDelta(MouseX);
	const float dY = Device.dwHeight * inputMap->GetFloatDelta(MouseY);
	// <<<

	mouseDelta.set(dX, dY);

	// here mouse click can trigger some receivers unreg so check vector again
	if (!AnyReceiver())	return;

	if (abs(dX) > eps || abs(dY) > eps)
	{
		receivers.back()->IR_OnMouseMove(dX, dY);
	} 
	else if (pdX != dX || pdY != dY)
	{
		// no move: deltas are 0 but we were moving the mouse before
		receivers.back()->IR_OnMouseStop(0,0);
	}

	pdX = dX;
	pdY = dY;
	
	if (!AnyReceiver())	return;

	const float dWheel = inputMap->GetFloatDelta(MouseWheel);
	if (abs(dWheel) > eps)
	{
		receivers.back()->IR_OnMouseWheel(dWheel);
	}

	if (!AnyReceiver())	return;

	gainput::InputState* state = keyboard->GetInputState();
	gainput::InputState* old_state = keyboard->GetPreviousInputState();

	const u32 buttonsCnt = state->GetButtonCount();
	for (int i = 0; i < buttonsCnt; i++)
	{
		if (!AnyReceiver()) return;

		const bool currState = state->GetBool(i);
		const bool prevState = old_state->GetBool(i);

		const int translatedButtonIdx = i + 1;

		// holding: was true and now true
		if (prevState && currState)
		{
			receivers.back()->IR_OnKeyboardHold(translatedButtonIdx);
			continue;
		}

		// press: was false and now true
		if (!prevState && currState)
		{
			receivers.back()->IR_OnKeyboardPress(translatedButtonIdx);
			continue;
		}

		// released: was true and now false
		if (prevState && !currState)
		{
			receivers.back()->IR_OnKeyboardRelease(translatedButtonIdx);
			continue;
		}
	}
}

float vibrateTime = 0;

void CInput::UpdateGamepad()
{
	if (vibrateTime <= Device.fTimeGlobal)
	{
		feedback(0, 0, 0);
	}

	gainput::InputState* padState = gamepad->GetInputState();
	
	receivers.back()->IR_OnMouseMove(padState->GetFloat(gainput::PadButtonRightStickX),
		padState->GetFloat(gainput::PadButtonRightStickY));

	if (padState->GetBool(gainput::PadButtonUp))
	{
		receivers.back()->IR_OnKeyboardHold(DIK_W);
	}
	if (padState->GetBool(gainput::PadButtonDown))
	{
		receivers.back()->IR_OnKeyboardHold(DIK_S);
	}
	if (padState->GetBool(gainput::PadButtonLeft))
	{
		receivers.back()->IR_OnKeyboardHold(DIK_A);
	}
	if (padState->GetBool(gainput::PadButtonRight))
	{
		receivers.back()->IR_OnKeyboardHold(DIK_D);
	}

	if (padState->GetBool(gainput::PadButtonR2))
	{
		receivers.back()->IR_OnMouseHold(0);
	}

	if (padState->GetBool(gainput::PadButtonA))
	{
		receivers.back()->IR_OnKeyboardHold(DIK_SPACE);
	}

	if (padState->GetBool(gainput::PadButtonX))
	{
		receivers.back()->IR_OnKeyboardHold(DIK_R);
	}

//	 gainput::PadButtonLeftStickX

}

void CInput::iCapture(IInputReceiver* ir)
{
	if (!receivers.empty())
	{
		receivers.back()->IR_OnDeactivate();
	}
	receivers.push_back(ir);
	ir->IR_OnActivate();
}

void CInput::iRelease(IInputReceiver* ir)
{
	if (!AnyReceiver())
	{
		Msg("! No input receivers present but IR->Release() called!");
		return;
	}

	if (ir == receivers.back())
	{
		ir->IR_OnDeactivate();
		receivers.pop_back();

		if (AnyReceiver())
			receivers.back()->IR_OnActivate();
	}
	else
	{
		receivers.erase(std::remove(receivers.begin(), receivers.end(), ir), receivers.end());
	}
}

#if defined(_WIN32)
void CInput::HandleMessage(tagMSG msg)
{
	if (inputManager == nullptr || inputMap == nullptr)
		return;

	inputManager->HandleMessage(msg);
}
#endif

CInput::~CInput()
{
	delete inputMap;
	delete inputManager;
}

void  CInput::feedback(u16 s1, u16 s2, float time)
{
	if (!gamepad->Vibrate(s1, s2))
		return;

	vibrateTime = Device.fTimeGlobal + time;
}