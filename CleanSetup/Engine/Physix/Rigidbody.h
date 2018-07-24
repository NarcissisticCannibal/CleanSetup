#pragma once

#include "../Math/Vector2.h"
#include "../Math/Vector3.h"

class Rigidbody {
public:

	Rigidbody();
	
	void Initialize(float _friction, Vector2* _pos, Vector2* _scale, float* _rot, Vector2 _size, float mass);
	void Update();
	void Render(Vector3 _color); //Debug only, eventually physics will not be rendered directly.

	void addForce(Vector2 _force);
	void addForce(Vector2 _force, Rigidbody* _source);

	void addMass(float _change);
	void addDrag(float _change);

private:

	/* Point at the corresponding values of the associated sprite and therefore texture */
	Vector2* pos;
	float* rot;
	Vector2* scale;
	Vector2 size;

	/* Very basic physics, will need to be upgraded */
	float mass;
	float drag; //drag coefficient for air resistance calculations

	float friction;
	Vector2 velocity;
};