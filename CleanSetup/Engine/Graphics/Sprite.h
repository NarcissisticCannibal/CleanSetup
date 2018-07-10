#pragma once

#include "Texture.h"
#include "../Math/Vector3.h"
#include <string>
#include "GLFW/glfw3.h"

class Sprite {
public:

	Sprite();
	Sprite(string path);
	Sprite(string path, Vector3 _pos);

	void Update();
	void Render();

	float getSpeed();

	void setSpeed(float _speed);
	void changeSpeed(float _change);
	void setPos(Vector3 _pos);
	void move(Vector3 _m); //Moves along the given vector
	void moveDirection(Vector3 _dir); //Moves in the direction of the given vector, distance normalized to speed
	void setRot(float _rot);
	void addRot(float _rot);
	void setScale(float _scale);
	void setScale(Vector3 _scale);

private:

	Texture texture;
	float speed;
	Vector3 pos;
	float rot;
	Vector3 scale;
};