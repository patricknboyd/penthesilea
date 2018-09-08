#pragma once
#include "stdafx.h"

class Ray
{
public:
	Vector3 Origin;
	Vector3 Direction;

	Ray();
	Ray(const Vector3& origin, const Vector3& direction);
};