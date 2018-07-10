#pragma once


#include <iostream>
#include "IO/Gamepad.h"
#include "GLFW/glfw3.h"

#pragma comment(lib, "opengl32.lib")

using namespace std;

class Engine {
public:

	static int SCR_WIDTH, SCR_HEIGHT;
	Gamepad gamepad;

	Engine();
	~Engine();

	static float getDT();

	int Initialize(const char* windowTitle);

	void Update();
	void BeginRender();
	void EndRender();



private:
	
	static GLFWwindow* myWindow;
	static float dt;
	float last;

};