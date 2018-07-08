#include "Keyboard.h"

bool Keyboard::keysHeld[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysDown[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysUp[GLFW_KEY_LAST] = { 0 };

void Keyboard::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key < 0) return;

	if (action != GLFW_RELEASE && !keysHeld[key]) {
		keysDown[key] = true;
		keysUp[key] = false;
	}

	if (action == GLFW_RELEASE && keysHeld[key]) {
		keysDown[key] = false;
		keysUp[key] = true;
	}

	keysHeld[key] = action != GLFW_RELEASE;
}

bool Keyboard::keyHeld(int key) {
	return keysHeld[key];
}

bool Keyboard::keyDown(int key) {
	bool tmp = keysDown[key];
	keysDown[key] = false;
	return tmp;
}

bool Keyboard::keyUp(int key) {
	bool tmp = keysUp[key];
	keysUp[key] = false;
	return tmp;
}
