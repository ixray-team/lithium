#pragma once

#include <dinput.h>

namespace gainput
{
	class InputManager;
	class InputMap;
	class InputDeviceKeyboard;
	class InputDeviceMouse;
	class InputDevicePad;
};

extern ENGINE_API class CInput* pInput;

#include <vector>

class ENGINE_API CInput :
	public pureFrame,
	public pureAppActivate,
	public pureAppDeactivate
{
public:

	enum
	{
		COUNT_KB_BUTTONS = 256,
		COUNT_MOUSE_BUTTONS = 8
	};

	CInput(bool bCaptureInput);
	virtual ~CInput();
	void OnWindowResize(int width, int height);
	virtual void OnFrame();
	virtual void OnAppActivate();
	virtual void OnAppDeactivate();

	class IInputReceiver* CurrentIR();
	void iCapture(class IInputReceiver* ir);
	void iRelease(class IInputReceiver* ir);

	int iGetAsyncKeyState(int dik);
	int iGetAsyncBtnState(int btn);

	void iGetLastMouseDelta(Ivector2& p);

	bool get_dik_name(int dik, LPSTR dest_str, int dest_sz);
	bool get_exclusive_mode() { return false; };
	void exclusive_mode(bool b) {};
	void feedback(u16 s1, u16 s2, float time);

#if defined(_WIN32)
	void HandleMessage(struct tagMSG msg);
#endif

private:

	void UpdateGamepad();

	unsigned int keyboardId;
	unsigned int mouseId;
	unsigned int gamepadId;
	gainput::InputManager* inputManager;
	gainput::InputMap* inputMap;

	gainput::InputDeviceKeyboard* keyboard;
	gainput::InputDeviceMouse* mouse; 
	gainput::InputDevicePad* gamepad;

	std::vector<class IInputReceiver*> receivers;
};