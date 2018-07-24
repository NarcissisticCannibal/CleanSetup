#include "../Engine.h"
#include "Sprite.h"
#include <math.h>
#include <algorithm>

#define SPEED 100

Sprite::Sprite() {
	speed = SPEED;
	rot = 0;
	pos = Vector2(0);
	scale = Vector2(1);
	texture = Texture();
}

Sprite::Sprite(string path) {
	speed = SPEED;
	rot = 0;
	pos = Vector2(0);
	scale = Vector2(1);
	texture = Texture(path);
}

Sprite::Sprite(string path, Vector2 _pos) {
	speed = SPEED;
	rot = 0;
	pos = _pos;
	scale = Vector2(1);
	texture = Texture(path);
}

void Sprite::Update() {

}

void Sprite::Render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.getID());
	glLoadIdentity();

	//Translate -> Rotate -> Scale
	glTranslatef(pos.x, pos.y, 0);

	glRotatef(rot, 0, 0, 1);

	glScalef(scale.x, scale.y, 1);

	glColor4f(1, 1, 1, 1);
	
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);		glVertex2i(0, 0);
	glTexCoord2f(1, 0);		glVertex2i(texture.getWidth(), 0);
	glTexCoord2f(1, 1);		glVertex2i(texture.getWidth(), texture.getHeight());
	glTexCoord2f(0, 1);		glVertex2i(0, texture.getHeight());
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

float Sprite::getSpeed() {
	return speed;
}

Vector2 Sprite::getSize() {
	return Vector2((float) texture.getWidth(), (float) texture.getHeight());
}

Vector2* Sprite::getPos() {
	return &pos;
}

float* Sprite::getRot() {
	return &rot;
}

Vector2* Sprite::getScale() {
	return &scale;
}

void Sprite::setSpeed(float _speed) {
	speed = std::max(0.0f, _speed);
}


void Sprite::changeSpeed(float _change) {
	setSpeed(speed + _change);
}

void Sprite::setPos(Vector2 _pos) {
	pos = _pos;
}

void Sprite::move(Vector2 _m) {
	pos = (pos + _m * speed * Engine::getDT());
}

void Sprite::moveDirection(Vector2 _dir) {
	move(_dir / _dir.mag());
}

void Sprite::setRot(float _rot) {
	rot = _rot;
	while (rot > 360) {
		rot -= 360;
	}
}

void Sprite::addRot(float _rot) {
	rot = (float) fmod(rot + _rot * Engine::getDT() * speed, 360.0);
}

void Sprite::setScale(float _scale) {
	scale.x = _scale;
	scale.y = _scale;
}

void Sprite::setScale(Vector2 _scale) {
	scale = _scale;
}