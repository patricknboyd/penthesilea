#pragma once
#include "stdafx.h"

class Box : public GeometricObject
{
public:
	Box();
	Box(Vector3 topLeft, Vector3 bottomRight);

	virtual bool Hit(const Ray& ray, Float& tMin, TraceResult& result) const;
	virtual bool HitShadowRay(const Ray& ray, Float &tMin) const;

private:

	Vector3 a, b;

	static const Float kEpsilon;
};
