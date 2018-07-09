#pragma once

#define NOMINMAX
#include <Windows.h>
#include <Xinput.h>

static const WORD XINPUT_Buttons[] = {
	XINPUT_GAMEPAD_A,
	XINPUT_GAMEPAD_B,
	XINPUT_GAMEPAD_X,
	XINPUT_GAMEPAD_Y,
	XINPUT_GAMEPAD_DPAD_UP,
	XINPUT_GAMEPAD_DPAD_DOWN,
	XINPUT_GAMEPAD_DPAD_LEFT,
	XINPUT_GAMEPAD_DPAD_RIGHT,
	XINPUT_GAMEPAD_LEFT_SHOULDER,
	XINPUT_GAMEPAD_RIGHT_SHOULDER,
	XINPUT_GAMEPAD_LEFT_THUMB,
	XINPUT_GAMEPAD_RIGHT_THUMB,
	XINPUT_GAMEPAD_START,
	XINPUT_GAMEPAD_BACK
};

struct XButtonIDs {
	XButtonIDs();

	int A, B, X, Y; 
	int dPadUp, dPadDown, dPadLeft, dPadRight;
	int lShoulder, rShoulder;
	int lStick, rStick;
	int start, back;
};

class Gamepad{
public:
	
	Gamepad();
	Gamepad(int _index);

	void Update();
	void RefreshState();

	bool lStickDeadzone();
	bool rStickDeadzone();

	float lStickX();
	float lStickY();
	float rStickX();
	float rStickY();

	float lTrigger();
	float rTrigger();

	bool buttonPressed(int _button);
	bool buttonDown(int _button);

	XINPUT_STATE getState();
	int getIndex();
	bool connected();

	void vibrate(float lMotor = 0, float rMotor = 0);

private:

	XINPUT_STATE state;
	int index;  //Range: 1 to 4

	static const int bCount = 14;

	bool prevButtonStates[bCount];
	bool bButtonStates[bCount];
	bool bButtonsDown[bCount];
};

extern XButtonIDs xButtons;