#include "stdafx.h"

const Vector3 Vector3::Zero = Vector3(0.0, 0.0, 0.0);
const Vector3 Vector3::Up = Vector3(0.0, 1.0, 0.0);
const Vector3 Vector3::Forward = Vector3(0.0, 0.0, -1.0);
const Vector3 Vector3::Right = Vector3(1.0, 0.0, 0.0);

Vector3::Vector3()
{
	X = 0.0;
	Y = 0.0;
	Z = 0.0;
}

Vector3::Vector3(Float x, Float y, Float z)
{
	X = x;
	Y = y;
	Z = z;
}

Float Vector3::Length() const
{
	return sqrt((X * X) + (Y * Y) + (Z * Z));
}

Float Vector3::Dot(const Vector3& a, const Vector3& b)
{
	return (a.X * b.X) + (a.Y * b.Y) + (a.Z * b.Z);
}

Float Vector3::Dot(const Vector3& other) const
{
	return Vector3::Dot(*this, other);
}

Vector3 Vector3::Cross(const Vector3& a, const Vector3& b)
{
	return Vector3(
		(a.Y * b.Z) - (a.Z * b.Y),
		(a.Z * b.X) - (a.X * b.Z),
		(a.X * b.Y) - (a.Y * b.X)
		);
}

Vector3 Vector3::Cross(const Vector3& other) const
{
	return Vector3::Cross(*this, other);
}

Vector3 Vector3::Normalize(const Vector3& vec)
{
	Float magnitude = vec.Length();

	return Vector3(vec.X / magnitude, vec.Y / magnitude, vec.Z / magnitude);
}

Vector3 Vector3::Normalize() const
{
	return Vector3::Normalize(*this);
}

Float Vector3::Distance(const Vector3 & a, const Vector3 & b)
{
	return (b - a).Length();
}

Float Vector3::Distance(const Vector3& other) const
{
	return Vector3::Distance(*this, other);
}

Vector3 Vector3::operator+ (const Vector3& other) const
{
	return Vector3(X + other.X, Y + other.Y, Z + other.Z);
}

Vector3 Vector3::operator- (const Vector3& other) const
{
	return Vector3(X - other.X, Y - other.Y, Z - other.Z);
}

//Vector3 Vector3::operator* (Float& factor) const
//{
//	return Vector3(X * factor, Y * factor, Z * factor);
//}

//Vector3 Vector3::operator/ (Float& denominator) const
//{
//	return Vector3(X / denominator, Y / denominator, Z / denominator);
//}