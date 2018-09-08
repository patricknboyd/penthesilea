#include "stdafx.h"

const Float Plane::kEpsilon = EPSILON;

Plane::Plane()
{
	_point = Vector3();
	_normal = Vector3(0.0, 0.0, -1.0f);
}

Plane::Plane(const Vector3& point, const Vector3& normal)
{
	_point = point;
	_normal = normal.Normalize();
}

bool Plane::Hit(const Ray& ray, Float& tMin, TraceResult& result) const
{
	Float t = (_point - ray.Origin).Dot(_normal) / ray.Direction.Dot( _normal);

	if (t > kEpsilon)
	{
		tMin = t;
		result.Normal = _normal;
		result.LocalHitPoint = ray.Origin + (ray.Direction * t);

		return true;
	}
	else
	{
		return false;
	}
}

bool Plane::HitShadowRay(const Ray& ray, Float& tMin) const
{
	Float t = (_point - ray.Origin).Dot(_normal) / ray.Direction.Dot(_normal);

	if (t > kEpsilon)
	{
		tMin = t;
		return true;
	}
	else
	{
		return false;
	}
}