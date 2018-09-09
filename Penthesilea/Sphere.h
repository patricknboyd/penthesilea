#pragma once
#include "GeometricObject.h"

class Sphere : public GeometricObject
{
public:
	Sphere();
	Sphere(const Vector3& center, Float radius);

	virtual bool Hit(const Ray& ray, Float& tMin, TraceResult& result) const;
	virtual bool HitShadowRay(const Ray& ray, Float &tMin) const;

private:

	Vector3 _center;
	Float _radius;
	Float _radiusSquared;

	static const Float kEpsilon;
};
