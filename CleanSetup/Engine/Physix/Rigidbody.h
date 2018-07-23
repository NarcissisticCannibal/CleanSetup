#pragma once

#include "../Math/Vector3.h"

class Rigidbody {
public:

	Rigidbody();
	
	void Initialize(float _gravity, float _friction, Vector3* _pos, Vector3* _scale, float* _rot, Vector3* _size);
	void Update();
	void Render(Vector3 _color); //Debug only, eventually physics will not be rendered directly.

	void addForce(Vector3 _force);

private:

	/* Point at the corresponding values of the associated sprite */
	Vector3* pos;
	float* rot;
	Vector3* scale;
	Vector3* size;

	/* Very basic physics, will need to be upgraded */
	float gravity;
	float friction;
	Vector3 velocity;
};