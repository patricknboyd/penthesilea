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