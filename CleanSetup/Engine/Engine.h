#pragma once

#include "GLFW/glfw3.h"
#include <iostream>
#pragma comment(lib, "opengl32.lib")

using namespace std;

class Engine {
public:

	static int SCR_WIDTH, SCR_HEIGHT;

	Engine();
	~Engine();

	int Initialize(const char* windowTitle);

	void Update();
	void BeginRender();
	void EndRender();

private:
	
	static GLFWwindow* myWindow;
};