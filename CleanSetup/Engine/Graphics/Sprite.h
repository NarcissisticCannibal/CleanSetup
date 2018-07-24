#pragma once

#include "Texture.h"
#include "../Math/Vector2.h"
#include <string>
#include "GLFW/glfw3.h"

class Sprite {
public:

	Sprite();
	Sprite(string path);
	Sprite(string path, Vector2 _pos);

	void Update();
	void Render();

	float getSpeed();
	Vector2 getSize();
	Vector2* getPos();
	float* getRot();
	Vector2* getScale();

	void setSpeed(float _speed);
	void changeSpeed(float _change);
	void setPos(Vector2 _pos);
	void move(Vector2 _m); //Moves along the given vector
	void moveDirection(Vector2 _dir); //Moves in the direction of the given vector, distance normalized to speed
	void setRot(float _rot);
	void addRot(float _rot);
	void setScale(float _scale);
	void setScale(Vector2 _scale);

private:

	Texture texture;
	float speed;
	Vector2 pos;
	float rot;
	Vector2 scale;
};