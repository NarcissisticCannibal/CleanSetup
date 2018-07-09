#include "Gamepad.h"

#pragma comment(lib, "Xinput.lib")

XButtonIDs xButtons;

XButtonIDs::XButtonIDs()
{
	A = 0;
	B = 1;
	X = 2;
	Y = 3;

	dPadUp = 4;
	dPadDown = 5;
	dPadLeft = 6;
	dPadRight = 7;

	lShoulder = 8;
	rShoulder = 9;

	lStick = 10;
	rStick = 11;

	start = 12;
	back = 13;
}

Gamepad::Gamepad() {
	for (int i = 0; i < bCount; i++) {
		prevButtonStates[i] = false;
		bButtonStates[i] = false;
		bButtonsDown[i] = false;
	}
}

Gamepad::Gamepad(int _index) {
	index = _index - 1;
	for (int i = 0; i < bCount; i++) {
		prevButtonStates[i] = false;
		bButtonStates[i] = false;
		bButtonsDown[i] = false;
	}
}

void Gamepad::Update() { //Get new state without returning it.
	state = getState();
	for (int i = 0; i < bCount; i++) {
		bButtonStates[i] = (state.Gamepad.wButtons & XINPUT_Buttons[i]) == XINPUT_Buttons[i];
		bButtonsDown[i] = !prevButtonStates[i] && bButtonStates[i];
	}
}

void Gamepad::RefreshState() {
	memcpy(prevButtonStates, bButtonStates,	sizeof(prevButtonStates));
}

bool Gamepad::lStickDeadzone() { //Assume state has just been updated
	short sX = state.Gamepad.sThumbLX;
	short sY = state.Gamepad.sThumbLY;
	
	if (sX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE || sX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) return false;
	if (sY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE || sY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) return false;

	return true; //Must be in both deadzones
}

bool Gamepad::rStickDeadzone() {
	short sX = state.Gamepad.sThumbRX;
	short sY = state.Gamepad.sThumbRY;

	if (sX > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE || sX < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) return false;
	if (sY > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE || sY < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) return false;

	return true; //Must be in both deadzones
}

float Gamepad::lStickX() {
	short s = state.Gamepad.sThumbLX;
	if (s > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE || s < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) return (static_cast<float>(s) / 32768.0f);
	return 0;
}

float Gamepad::lStickY() {
	short s = state.Gamepad.sThumbLY;
	if (s > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE || s < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) return (static_cast<float>(s) / 32768.0f);
	return 0;
}

float Gamepad::rStickX() {
	short s = state.Gamepad.sThumbRX;
	if (s > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE || s < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) return (static_cast<float>(s) / 32768.0f);
	return 0;
}

float Gamepad::rStickY() {
	short s = state.Gamepad.sThumbRY;
	if (s > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE || s < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) return (static_cast<float>(s) / 32768.0f);
	return 0;
}

float Gamepad::lTrigger() {
	BYTE trigger = state.Gamepad.bLeftTrigger;
	if (trigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD) return trigger / 255.0f;
	return 0;
}

float Gamepad::rTrigger() {
	BYTE trigger = state.Gamepad.bRightTrigger;
	if (trigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD) return trigger / 255.0f;
	return 0;
}

bool Gamepad::buttonPressed(int _button) {
	if (state.Gamepad.wButtons & XINPUT_Buttons[_button]) return true;
	return false;
}

bool Gamepad::buttonDown(int _button) {
	return bButtonsDown[_button];
}

XINPUT_STATE Gamepad::getState() {
	XINPUT_STATE gamepadState;
	RtlSecureZeroMemory(&gamepadState, sizeof(XINPUT_STATE)); //Ensure memory is clean
	XInputGetState(index, &gamepadState);
	return gamepadState;
}

int Gamepad::getIndex() {
	return index;
}

bool Gamepad::connected() { //Technically also pulls a new state
	RtlSecureZeroMemory(&state, sizeof(XINPUT_STATE));
	DWORD result = XInputGetState(index, &state);
	if (result == ERROR_SUCCESS)
		return true;
	else
		return false;
}

void Gamepad::vibrate(float _lMotor, float _rMotor) {
	XINPUT_VIBRATION vibState;
	RtlSecureZeroMemory(&vibState, sizeof(XINPUT_VIBRATION));

	int lMotor = int(_lMotor * 65535.0f);
	int rMotor = int(_rMotor * 65535.0f);

	vibState.wLeftMotorSpeed = lMotor;
	vibState.wRightMotorSpeed = rMotor;

	XInputSetState(index, &vibState);
}