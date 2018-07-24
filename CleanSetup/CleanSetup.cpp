#include <iostream>

#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/IO/Gamepad.h"
#include "GameElements/Player.h"

using namespace std;

int main(){
	
	Engine engine;

	engine.Initialize("OpenGL Testing");

	//Sprite testSprite = Sprite("Assets/Sprites/crude1.png", Vector2(100, 100));
	Player player = Player();
	player.Initialize("Assets/Sprites/v2.png", Vector2(100, 100), 1, 1);

	bool running = true;

	while (running) {

		engine.Update();
		player.Update();
		//testSprite.setPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());
		engine.gamepad.Update();
		Vector2 dir = Vector2(engine.gamepad.lStickX(), engine.gamepad.lStickY());
		player.playerS.moveDirection(dir);
		if (engine.gamepad.buttonDown(xButtons.A)) player.playerS.changeSpeed(10);
		if (engine.gamepad.buttonDown(xButtons.B)) player.playerS.changeSpeed(-10);
		if (engine.gamepad.buttonDown(xButtons.back)) running = false;
		engine.gamepad.RefreshState();

		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_1)) {
			player.playerS.addRot(1);
		}

		if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_2)) {
			player.playerS.addRot(-1);
		}

		if (Keyboard::keyHeld(GLFW_KEY_W)) {
			player.playerS.moveDirection(Vector2(0, 10));
		}

		if (Keyboard::keyHeld(GLFW_KEY_A)) {
			player.playerS.moveDirection(Vector2(-10, 0));
		}

		if (Keyboard::keyHeld(GLFW_KEY_S)) {
			player.playerS.moveDirection(Vector2(0, -10));
		}

		if (Keyboard::keyHeld(GLFW_KEY_D)) {
			player.playerS.moveDirection(Vector2(10, 0));
		}

		if (Keyboard::keyHeld(GLFW_KEY_ESCAPE)) {
			running = false;
		}

		engine.BeginRender();

		player.Render();

		engine.EndRender();
	}

	glfwTerminate();

	cout << "Press any key to terminate" << endl;

	getchar();

	return 0;
}