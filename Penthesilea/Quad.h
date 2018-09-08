#pragma once
#include "stdafx.h"

class Quad : public GeometricObject
{
public:
	Quad();
	Quad(Vector3 cornerPoint, Vector3 sideOne, Vector3 sideTwo);

	virtual bool Hit(const Ray& ray, Float& tMin, TraceResult& result) const;
	virtual bool HitShadowRay(const Ray& ray, Float &tMin) const;

private:

	Vector3 corner;
	Vector3 a, b;

	Float aLengthSquared;
	Float bLengthSquared;

	Vector3 normal;

	static const Float kEpsilon;
};