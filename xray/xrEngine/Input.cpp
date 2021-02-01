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


enum
{
	MouseX,
	MouseY
};

CInput::CInput(bool bCaptureInput) : receivers()
{
	inputManager = new gainput::InputManager();
	keyboardId = inputManager->CreateDevice<gainput::InputDeviceKeyboard>();
	mouseId = inputManager->CreateDevice<gainput::InputDeviceMouse>();
	gamepadId = inputManager->CreateDevice<gainput::InputDevicePad>();

	keyboard = (gainput::InputDeviceKeyboard*) inputManager->GetDevice(keyboardId);
	mouse = (gainput::InputDeviceMouse*) inputManager->GetDevice(mouseId);

	inputMap = new gainput::InputMap(*inputManager);
	inputMap->MapFloat(MouseX, mouseId, gainput::MouseAxisX);
	inputMap->MapFloat(MouseY, mouseId, gainput::MouseAxisY);
}

void CInput::OnWindowResize(int width, int height)
{
	inputManager->SetDisplaySize(width, height);
}

void CInput::OnAppDeactivate()
{
}

void CInput::OnAppActivate()
{
}

IInputReceiver* CInput::CurrentIR()
{
	if (!receivers.empty())
	{
		return receivers.back();
	}
	return nullptr;
}

int CInput::iGetAsyncKeyState(int dik) // 1 -> Release, 0 -> Press
{
	return 0;
}

void CInput::iGetLastMouseDelta(Ivector2& p)
{
}

int CInput::iGetAsyncBtnState(int btn)
{
	return 0;
}

bool CInput::get_dik_name(int dik, LPSTR dest_str, int dest_sz)
{
	return false;
}

void CInput::OnFrame()
{
	inputManager->Update();

	if (receivers.empty())
	{
		return;
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
	if (receivers.back() == ir)
	{
		receivers.back()->IR_OnDeactivate();
		receivers.pop_back();
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
}