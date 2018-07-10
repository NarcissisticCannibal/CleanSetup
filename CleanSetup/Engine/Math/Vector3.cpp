#include "Vector3.h"

Vector3::Vector3() {
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float _v) {
	x = _v;
	y = _v;
	z = _v;
}

Vector3::Vector3(float _x, float _y) {
	x = _x;
	y = _y;
	z = 0;
}

Vector3::Vector3(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}

Vector3::Vector3(const Vector3& other) {
	x = other.x;
	y = other.y;
	z = other.z;
}

Vector3& Vector3::operator=(const Vector3& other) {
	x = other.x;
	y = other.y;
	z = other.z;

	return *this;
}

Vector3 Vector3::operator+(const Vector3& other) {
	Vector3 ret;
	ret.x = x + other.x;
	ret.y = y + other.y;
	ret.z = z + other.z;
	return ret;
}

Vector3 Vector3::operator-(const Vector3& other) {
	Vector3 ret;
	ret.x = x - other.x;
	ret.y = y - other.y;
	ret.z = z - other.z;
	return ret;
}

Vector3 Vector3::operator*(const Vector3& other) {
	Vector3 ret;
	ret.x = x * other.x;
	ret.y = y * other.y;
	ret.z = z * other.z;
	return ret;
}

Vector3 Vector3::operator*(float _v) {
	Vector3 ret;
	ret.x = x * _v;
	ret.y = y * _v;
	ret.z = z * _v;
	return ret;
}

Vector3 Vector3::operator/(float _v) {
	if (_v == 0) return Vector3();
	Vector3 ret;
	ret.x = x / _v;
	ret.y = y / _v;
	ret.z = z / _v;
	return ret;
}

float Vector3::mag() {
	return (float) sqrt(x * x + y * y + z * z);
}

bool Vector3::operator==(const Vector3& other) {
	return (x == other.x && y == other.y && z == other.z);
}

bool Vector3::operator!=(const Vector3& other) {
	return !(x == other.x && y == other.y && z == other.z);
}