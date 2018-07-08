#pragma once

#include "GLFW/glfw3.h"

class Mouse {
public:

	static void MousePosCallback(GLFWwindow* window, double _mX, double _mY);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	static double getMouseX();
	static double getMouseY();

	static bool ButtonDown(int button);
	static bool ButtonUp(int button);
	static bool ButtonHeld(int button);

private:

	static double mX, mY;

	static bool buttonsHeld[], buttonsDown[], buttonsUp[];


};