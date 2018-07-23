#include "Rigidbody.h"
#include "../Engine.h"

Rigidbody::Rigidbody() {
	friction = 1;
	gravity = 0;
}

void Rigidbody::Initialize(float _gravity, float _friction, Vector3* _pos, Vector3* _scale, float* _rot, Vector3* _size) {
	gravity = _gravity;
	friction = _friction;
	pos = _pos;
	scale = _scale;
	rot = _rot;
	size = _size;
}

void Rigidbody::Update() {
	velocity.x *= friction;
	velocity.y -= gravity;
	*pos = *pos + (velocity * Engine::getDT());
}

void Rigidbody::Render(Vector3 _color) {
	glLoadIdentity();

	glTranslatef(pos->x, pos->y, 0);
	glRotatef(*rot, 0, 0, 1);
	glScalef(scale->x, scale->y, 1);

	glColor4f(_color.x, _color.y, _color.z, 1);

	glBegin(GL_LINES);

	glVertex2i(0, 0);
	glVertex2i((int) size->x, 0);

	glVertex2i((int)size->x, 0);
	glVertex2i((int) size->x, (int) size->y);

	glVertex2i((int)size->x, (int)size->y);
	glVertex2i(0, (int) size->y);

	glVertex2i(0, (int)size->y);
	glVertex2i(0, 0);

	glEnd();
}

void Rigidbody::addForce(Vector3 _force) {
	velocity = velocity + _force; //TODO: Make this meaningful
}