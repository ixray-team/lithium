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

CInput::CInput(bool bCaptureInput) : receivers()
{
	inputManager = new gainput::InputManager(false);
	keyboardId = inputManager->CreateDevice<gainput::InputDeviceKeyboard>();
	mouseId = inputManager->CreateDevice<gainput::InputDeviceMouse>();
	gamepadId = inputManager->CreateDevice<gainput::InputDevicePad>();

	keyboard = (gainput::InputDeviceKeyboard*) inputManager->GetDevice(keyboardId);
	mouse = (gainput::InputDeviceMouse*) inputManager->GetDevice(mouseId);
	gamepad = (gainput::InputDevicePad*) inputManager->GetDevice(gamepadId);

	inputMap = new gainput::InputMap(*inputManager);
	inputMap->MapFloat(MouseX, mouseId, gainput::MouseAxisX);
	inputMap->MapFloat(MouseY, mouseId, gainput::MouseAxisY);
	inputMap->MapFloat(MouseWheel, mouseId, gainput::MouseButtonWheelDown);


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

	if (receivers.empty())
	{
		return;
	}

	if (gamepad->IsAvailable())
	{
		UpdateGamepad();
		//return;
	}

	gainput::InputState* mouse_state = mouse->GetInputState();
	gainput::InputState* prev_state = mouse->GetPreviousInputState();

	for (int i = 0; i <= mouse_state->GetButtonCount(); i++)
	{
		if (mouse_state->GetBool(i))
		{
			if (prev_state->GetBool(i))
			{
				receivers.back()->IR_OnMouseHold(i < 2 ? i : i + 100);
			}
			else
			{
				receivers.back()->IR_OnMousePress(i < 2 ? i : i + 100);
			}
		}
		else
		{
			receivers.back()->IR_OnMouseRelease(i < 2 ? i : i + 100);
		}
	}

	if (inputMap->GetFloatDelta(MouseX) != 0.0f && inputMap->GetFloatDelta(MouseY))
	{
		receivers.back()->IR_OnMouseMove(inputMap->GetFloatDelta(MouseX), inputMap->GetFloatDelta(MouseY));
	}
	
	//IR_OnMouseStop???

	if (inputMap->GetFloatDelta(MouseWheel) != 0.0f)
	{
		receivers.back()->IR_OnMouseWheel(inputMap->GetFloatDelta(MouseWheel));
	}

	auto state = keyboard->GetInputState();
	auto old_state = keyboard->GetPreviousInputState();

	for (int i = 0; i <= state->GetButtonCount(); i++)
	{
		if (state->GetBool(i))
		{
			if (old_state->GetBool(i))
			{
				receivers.back()->IR_OnKeyboardHold(i + 1);
				continue;
			}
			receivers.back()->IR_OnKeyboardPress(i + 1);
		}
		else if(old_state->GetBool(i))
		{
			receivers.back()->IR_OnKeyboardRelease(i + 1);
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
	receivers.back()->IR_OnActivate();
}

void CInput::iRelease(IInputReceiver* ir)
{
	if (ir == receivers.back())
	{
		receivers.back()->IR_OnDeactivate();
		receivers.pop_back();
		if (!receivers.empty())
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
	vibrateTime = Device.fTimeGlobal + time;
	gamepad->Vibrate(s1, s2);
}