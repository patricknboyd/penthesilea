#include "stdafx.h"

const Float Box::kEpsilon = 0.001;

Box::Box()
	: Box(Vector3(0.0, 0.0, 0.0), Vector3(10, 10, -10))
{}

Box::Box(Vector3 topLeft, Vector3 bottomRight)
{
	a = topLeft;
	b = bottomRight;
}

bool Box::Hit(const Ray& ray, Float& tMin, TraceResult& result) const
{
	throw "Not implemented. See Page 357.";
}

bool Box::HitShadowRay(const Ray& shadowRay, Float& tMin) const
{
	return false;
}