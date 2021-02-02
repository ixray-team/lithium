#pragma once
#include <vector>

#pragma comment(lib, "Xinput9_1_0.lib")
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


class ENGINE_API CInput :
	public pureFrame,
	public pureAppActivate,
	public pureAppDeactivate
{
public:

	enum
	{
		COUNT_KB_BUTTONS = 256,
		COUNT_MOUSE_BUTTONS = 8		// 20 on Thrust GXT144 so not valid!
									// same would be for any A4 or other gamer mouse
									// see new buttons linsting method in .ctor
	};

private:
	inline bool AnyReceiver();

public:
	virtual void OnFrame();
	virtual void OnAppActivate();
	virtual void OnAppDeactivate();

public:
	CInput(bool bCaptureInput);
	virtual ~CInput();
	void OnWindowResize(int width, int height);

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

	gainput::InputManager* inputManager = nullptr;
	gainput::InputMap* inputMap = nullptr;

	unsigned int keyboardId = 0;
	gainput::InputDeviceKeyboard* keyboard = nullptr;

	unsigned int mouseId = 0;
	gainput::InputDeviceMouse* mouse = nullptr;
	std::vector<u8> mouseButtons;
	Ivector2 mouseDelta;

	unsigned int gamepadId = 0;
	gainput::InputDevicePad* gamepad = nullptr;


	std::vector<class IInputReceiver*> receivers;
};