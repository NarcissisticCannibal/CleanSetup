#pragma once

class Vector2 {
public:

	float x, y;

	Vector2();
	Vector2(float _v);
	Vector2(float _x, float _y);
	Vector2(const Vector2& other);

	Vector2& operator=(const Vector2& other);
	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2 operator*(const Vector2& other);
	Vector2 operator/(float _v); //Returns zero vector when dividing by zero.
	Vector2 operator*(float _v);

	float mag();

	bool operator==(const Vector2& other);
	bool operator!=(const Vector2& other);

private:



};