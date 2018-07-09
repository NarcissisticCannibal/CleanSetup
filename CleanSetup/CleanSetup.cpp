#include <iostream>

#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/IO/Gamepad.h"

using namespace std;

int main(){
	
	Engine engine;

	engine.Initialize("OpenGL Testing");

	Sprite testSprite = Sprite("Assets/Sprites/crude1.png", 100, 100);

	while (true) {

		engine.Update();
		testSprite.Update();
		//testSprite.setPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());
		testSprite.setScale(2.0);
		engine.gamepad.Update();
		testSprite.moveDirection(engine.gamepad.lStickX(), engine.gamepad.lStickY());
		if (engine.gamepad.buttonDown(xButtons.A)) testSprite.changeSpeed(10);
		if (engine.gamepad.buttonDown(xButtons.B)) testSprite.changeSpeed(-10);
		engine.gamepad.RefreshState();

		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_1)) {
			testSprite.addRot(10.0);
		}

		if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_2)) {
			testSprite.addRot(-10.0);
		}

		if (Keyboard::keyHeld(GLFW_KEY_W)) {
			testSprite.move(0, 1);
		}

		if (Keyboard::keyHeld(GLFW_KEY_A)) {
			testSprite.move(-1, 0);
		}

		if (Keyboard::keyHeld(GLFW_KEY_S)) {
			testSprite.move(0, -1);
		}

		if (Keyboard::keyHeld(GLFW_KEY_D)) {
			testSprite.move(1, 0);
		}

		engine.BeginRender();

		testSprite.Render();

		engine.EndRender();
	}

	glfwTerminate();

	return 0;
}