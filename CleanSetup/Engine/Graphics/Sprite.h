#pragma once

#include "Texture.h"
#include <iostream>
#include <string>
#include "GLFW/glfw3.h"

using namespace std;

class Sprite {
public:

	Sprite();
	Sprite(string path);
	Sprite(string path, float _xPos, float _yPos);

	void Update();
	void Render();

	float getSpeed();

	void setSpeed(float _speed);
	void changeSpeed(float _change);
	void setPos(float _xPos, float _yPos);
	void move(float _x, float _y);
	void moveDirection(float _x, float _y);
	void setRot(float _rot);
	void addRot(float _rot);
	void setScale(float scale);
	void setScale(float _xScale, float _yScale);

private:

	Texture texture;
	float speed;
	float xPos, yPos;
	float rot;
	float xScale, yScale;
};