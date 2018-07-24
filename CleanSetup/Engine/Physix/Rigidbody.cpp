#include <iostream>
#include "Rigidbody.h"
#include "../Engine.h"

/* These are constant for now, may become variable later. */
#define GRAVITY -1.0f
#define MINIMUM_MASS 0.1f
#define MINIMUM_DRAG 0.1f

Rigidbody::Rigidbody() {
	friction = 1;
	mass = 1;
	drag = 0.001;
	velocity = Vector2();
}

void Rigidbody::Initialize(float _friction, Vector2* _pos, Vector2* _scale, float* _rot, Vector2 _size, float _mass) {
	friction = _friction;
	pos = _pos;
	scale = _scale;
	rot = _rot;
	size = _size;
	mass = _mass;
}

void Rigidbody::Update() {
	// TODO: Friction if object is experiencing it

	// Gravitational acceleration, maybe make gravity variable to be gotten from current level?
	
	Vector2 air = (velocity * velocity) * (velocity.direction() * -1.0f) * (drag);
	addForce(Vector2(0.0, GRAVITY));
	addForce(air);

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
	glVertex2i((int) size.x, 0);

	glVertex2i((int)size.x, 0);
	glVertex2i((int) size.x, (int) size.y);

	glVertex2i((int)size.x, (int)size.y);
	glVertex2i(0, (int) size.y);

	glVertex2i(0, (int)size.y);
	glVertex2i(0, 0);

	glEnd();
}

void Rigidbody::addForce(Vector2 _force) {
	Vector2 acc = _force / mass;
	velocity = velocity + acc;
}

// When force originates from a collision, apply equal & opposite force to the other body
void Rigidbody::addForce(Vector2 _force, Rigidbody * _source) {
	addForce(_force);
	_source->addForce(_force * -1.0f);
}

/* We want to ensure mass and drag are always positive and above a certain minimum value */
void Rigidbody::addMass(float _change) {
	mass += _change;
	if (mass < MINIMUM_MASS) mass = MINIMUM_MASS;
}

void Rigidbody::addDrag(float _change) {
	drag += _change;
	if (drag < MINIMUM_DRAG) drag = MINIMUM_DRAG;
}