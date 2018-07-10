#pragma once

#include <math.h>

class Vector3 {
public:
	
	float x, y, z;

	Vector3();
	Vector3(float _v);
	Vector3(float _x, float _y);
	Vector3(float _x, float _y, float _z);
	Vector3(const Vector3& other);

	Vector3& operator=(const Vector3& other);
	Vector3 operator+(const Vector3& other);
	Vector3 operator-(const Vector3& other);
	Vector3 operator*(const Vector3& other);
	Vector3 operator/(float _v); //Returns zero vector when dividing by zero.
	Vector3 operator*(float _v);

	float mag();

	bool operator==(const Vector3& other);
	bool operator!=(const Vector3& other);

private:



};