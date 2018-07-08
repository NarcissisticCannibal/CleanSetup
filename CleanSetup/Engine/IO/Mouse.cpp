#include "Mouse.h"

double Mouse::mX = 0;
double Mouse::mY = 0;

bool Mouse::buttonsHeld[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::MousePosCallback(GLFWwindow * window, double _mX, double _mY) {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	mX = _mX;
	mY = height - _mY;
}

void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button < 0) return;

	if (action != GLFW_RELEASE && !buttonsHeld[button]) {
		buttonsDown[button] = true;
		buttonsUp[button] = false;
	}

	if (action == GLFW_RELEASE && buttonsHeld[button]) {
		buttonsDown[button] = false;
		buttonsUp[button] = true;
	}

	buttonsHeld[button] = action != GLFW_RELEASE;
}

double Mouse::getMouseX() {
	return mX;
}

double Mouse::getMouseY() {
	return mY;
}

bool Mouse::ButtonDown(int button) { //Make sure to only catch a button down once, so reset it before returning.
	bool tmp = buttonsDown[button];
	buttonsDown[button] = false;
	return tmp;
}

bool Mouse::ButtonUp(int button) { //Make sure to only catch a button up once, so reset it before returning.
	bool tmp = buttonsUp[button];
	buttonsUp[button] = false;
	return tmp;
}

bool Mouse::ButtonHeld(int button) {
	return buttonsHeld[button];
}