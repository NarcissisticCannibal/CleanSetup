#include "Engine.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"

int Engine::SCR_HEIGHT = 600;
int Engine::SCR_WIDTH = 1024;
GLFWwindow* Engine::myWindow = NULL;

Engine::Engine() {
	
}

Engine::~Engine() {

}

void resizeCallback(GLFWwindow* window, int width, int height);

int Engine::Initialize(const char* windowTitle) {

	if (glfwInit() == GL_FALSE) {
		cout << "glfwInit failed." << endl;
		return -1;
	}

	int major, minor, rev;

	glfwGetVersion(&major, &minor, &rev);

	cout << major << "." << minor << ":" << rev << endl;

	for (int i = 0; i < GLFW_JOYSTICK_LAST; i++) {
		int re = glfwJoystickPresent(i + 1);
		cout << re << endl;
	}

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

	return 0;
}

void Engine::Update() {

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