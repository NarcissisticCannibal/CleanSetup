#include "Sprite.h"
#include <math.h>

Sprite::Sprite() {
	rot = 0;
	xPos = 0;
	yPos = 0;
	texture = Texture();
}

Sprite::Sprite(string path) {
	rot = 0;
	xPos = 0;
	yPos = 0;
	texture = Texture(path);
}

Sprite::Sprite(string path, float _xPos, float _yPos) {
	rot = 0;
	xPos = _xPos;
	yPos = _yPos;
	texture = Texture(path);
}

void Sprite::Update() {

}

void Sprite::Render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.getID());
	glLoadIdentity();

	//Translate -> Rotate -> Scale
	glTranslatef(xPos, yPos, 0);

	glRotatef(rot, 0, 0, 1);

	glScalef(xScale, yScale, 1);

	glColor4f(1, 1, 1, 1);
	
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);		glVertex2f(0, 0);
	glTexCoord2f(1, 0);		glVertex2f(texture.getWidth(), 0);
	glTexCoord2f(1, 1);		glVertex2f(texture.getWidth(), texture.getHeight());
	glTexCoord2f(0, 1);		glVertex2f(0, texture.getHeight());
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::setPos(float _xPos, float _yPos) {
	xPos = _xPos;
	yPos = _yPos;
}

void Sprite::move(float _x, float _y) {
	xPos += _x;
	yPos += _y;
}

void Sprite::setRot(float _rot) {
	rot = fmod(_rot, 360.0);
}

void Sprite::addRot(float _rot) {
	rot = fmod(rot + _rot, 360.0);
}

void Sprite::setScale(float scale) {
	xScale = scale;
	yScale = scale;
}

void Sprite::setScale(float _xScale, float _yScale) {
	xScale = _xScale;
	yScale = _yScale;
}