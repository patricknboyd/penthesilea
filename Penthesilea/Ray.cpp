#include "stdafx.h"

Ray::Ray()
{
	Origin = Vector3(0.0, 0.0, 0.0);
	Direction = Vector3(1.0, 0.0, 0.0);
}

Ray::Ray(const Vector3& origin, const Vector3& direction)
{
	Origin = origin;
	Direction = direction;
}