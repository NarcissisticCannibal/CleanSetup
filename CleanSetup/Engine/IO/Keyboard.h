#pragma once

#include "GLFW/glfw3.h"

class Keyboard {
public:

	static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);

	static bool keyHeld(int key);
	static bool keyDown(int key);
	static bool keyUp(int key);

private:

	static bool keysHeld[];
	static bool keysDown[];
	static bool keysUp[];

};