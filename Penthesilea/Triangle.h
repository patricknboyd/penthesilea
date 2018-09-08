#pragma once
#include "stdafx.h"

class Triangle : public GeometricObject
{
public:
	Triangle();
	Triangle(Vector3 vertex1, Vector3 vertex2, Vector3 vertex3);

	virtual bool Hit(const Ray& ray, Float& tMin, TraceResult& result) const;
	virtual bool HitShadowRay(const Ray& ray, Float &tMin) const;

private:

	Vector3 v0, v1, v2;
	Vector3 normal;

	static const Float kEpsilon;

	void CalculateNormal();
};