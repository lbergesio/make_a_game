#include "vector2d.h"

Vector2D& Vector2D::Add(const Vector2D& vec){
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}

Vector2D& Vector2D::Subtract(const Vector2D& vec){
	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}

Vector2D& Vector2D::Multiply(const Vector2D& vec){
	this->x *= vec.x;
	this->y *= vec.y;

	return *this;
}

Vector2D& Vector2D::Divide(const Vector2D& vec){
	this->x /= vec.x;
	this->y /= vec.y;

	return *this;
}

Vector2D& operator+(Vector2D& v1, const Vector2D& v2){
	return v1.Add(v2);
}

Vector2D& operator-(Vector2D& v1, const Vector2D& v2){
	return v1.Subtract(v2);
}

Vector2D& operator*(Vector2D& v1, const Vector2D& v2){
	return v1.Multiply(v2);
}

Vector2D& operator/(Vector2D& v1, const Vector2D& v2){
	return v1.Divide(v2);
}

Vector2D& Vector2D::operator+=(const Vector2D& v2){
	return this->Add(v2);
}

Vector2D& Vector2D::operator-=(const Vector2D& v2){
	return this->Subtract(v2);
}

Vector2D& Vector2D::operator*=(const Vector2D& v2){
	return this->Multiply(v2);
}

Vector2D& Vector2D::operator/=(const Vector2D& v2){
	return this->Divide(v2);
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vec){
	stream << "(" << vec.x << ", " << vec.y << ")";
	return stream;
}
