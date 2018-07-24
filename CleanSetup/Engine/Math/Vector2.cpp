#include "Vector2.h"
#include <math.h>

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(float _v) {
	x = _v;
	y = _v;
}

Vector2::Vector2(float _x, float _y) {
	x = _x;
	y = _y;
}

Vector2::Vector2(const Vector2& other) {
	x = other.x;
	y = other.y;
}

Vector2& Vector2::operator=(const Vector2& other) {
	x = other.x;
	y = other.y;

	return *this;
}

Vector2 Vector2::operator+(const Vector2& other) {
	Vector2 ret;
	ret.x = x + other.x;
	ret.y = y + other.y;
	return ret;
}

Vector2 Vector2::operator-(const Vector2& other) {
	Vector2 ret;
	ret.x = x - other.x;
	ret.y = y - other.y;
	return ret;
}

Vector2 Vector2::operator*(const Vector2& other) {
	Vector2 ret;
	ret.x = x * other.x;
	ret.y = y * other.y;
	return ret;
}

Vector2 Vector2::operator*(float _v) {
	Vector2 ret;
	ret.x = x * _v;
	ret.y = y * _v;
	return ret;
}

Vector2 Vector2::direction() {
	Vector2 ret;
	if (x > 0) ret.x = 1;
	else if (x < 0) ret.x = -1;
	else ret.x = 0;

	if (y > 0) ret.y = 1;
	else if (y < 0) ret.y = -1;
	else ret.y = 0;

	return ret;
}

Vector2 Vector2::operator/(float _v) {
	if (_v == 0) return Vector2();
	Vector2 ret;
	ret.x = x / _v;
	ret.y = y / _v;
	return ret;
}

float Vector2::mag() {
	return (float)sqrt(x * x + y * y);
}

bool Vector2::operator==(const Vector2& other) {
	return (x == other.x && y == other.y);
}

bool Vector2::operator!=(const Vector2& other) {
	return (x != other.x || y != other.y);
}