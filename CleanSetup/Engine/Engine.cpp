#include "Engine.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"

int Engine::SCR_HEIGHT = 600;
int Engine::SCR_WIDTH = 1024;
GLFWwindow* Engine::myWindow = NULL;
float Engine::dt = 0;

Engine::Engine() {
	
}

Engine::~Engine() {

}

float Engine::getDT() {
	return dt;
}

void resizeCallback(GLFWwindow* window, int width, int height);

int Engine::Initialize(const char* windowTitle) {

	gamepad = Gamepad(1);

	if (gamepad.connected()) cout << "Gamepad 1 connected!" << endl;

	if (glfwInit() == GL_FALSE) {
		cout << "glfwInit failed." << endl;
		return -1;
	}

	int major, minor, rev;

	glfwGetVersion(&major, &minor, &rev);

	cout << "GLFW Version: " << major << "." << minor << ":" << rev << endl;

	myWindow = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, windowTitle, NULL, NULL);

	if (myWindow == NULL) {
		cout << "Couldn't create window. Sorry." << endl;
		return -2;
	}
	//Setup GLFW
	glfwMakeContextCurrent(myWindow);
	int width, height;
	glfwGetFramebufferSize(myWindow, &width, &height);
	glfwSwapInterval(1);

	glfwSetCursorPosCallback(myWindow, Mouse::MousePosCallback);
	glfwSetMouseButtonCallback(myWindow, Mouse::MouseButtonCallback);
	glfwSetKeyCallback(myWindow, Keyboard::keyCallBack);
	//glfwSetFramebufferSizeCallback(myWindow, resizeCallback);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCR_WIDTH) / 2;
	int yPos = (mode->height - SCR_HEIGHT) / 2;
	glfwSetWindowPos(myWindow, xPos, yPos);

	//Setup GL
	//Viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);

	//Alpha Blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	last = (float) glfwGetTime();

	return 0;
}

void Engine::Update() {
	float now = (float) glfwGetTime();
	dt = now - last;
	last = now;
	glfwPollEvents();
}

void Engine::BeginRender() {
	glClearColor(0, 0, 1, 1); //Blue
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::EndRender(){
	glfwSwapBuffers(myWindow);
}

void resizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}