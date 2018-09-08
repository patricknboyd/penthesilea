#pragma once
#include "stdafx.h"

class Plane : public GeometricObject
{
public:
	Plane();
	Plane(const Vector3& point, const Vector3& normal);

	virtual bool Hit(const Ray& ray, Float& tMin, TraceResult& result) const;
	virtual bool HitShadowRay(const Ray& ray, Float &tMin) const;

private:

	Vector3 _point;
	Vector3 _normal;

	static const Float kEpsilon;

};
