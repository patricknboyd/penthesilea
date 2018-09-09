#include "stdafx.h"

const Float Quad::kEpsilon = 0.001;

Quad::Quad()
	: Quad(Vector3(0.0, 0.0, 0.0), Vector3(10.0, 0.0, 0.0), Vector3(0.0, 20.0, 0.0))
{}

// Arguments should be top-left, down, right.
Quad::Quad(Vector3 cornerPoint, Vector3 sideOne, Vector3 sideTwo)
{
	corner = cornerPoint;
	a = sideOne;
	b = sideTwo;

	aLengthSquared = pow(a.Length(), 2);
	bLengthSquared = pow(b.Length(), 2);

	normal = Vector3::Cross(a, b);
}

bool Quad::Hit(const Ray& ray, Float& tMin, TraceResult& result) const
{
	double t = Vector3::Dot(corner - ray.Origin, normal / Vector3::Dot(ray.Direction, normal));

	if (t <= kEpsilon)
	{
		return (false);
	}

	Vector3 p = ray.Origin + t * ray.Direction;
	Vector3 d = p - corner;

	double ddota = Vector3::Dot(d, a);

	if (ddota < 0.0 || ddota > aLengthSquared)
	{
		return (false);
	}

	double ddotb = Vector3::Dot(d, b);

	if (ddotb < 0.0 || ddotb > bLengthSquared)
	{
		return (false);
	}

	tMin = t;
	result.Normal = normal;
	result.LocalHitPoint = p;

	return (true);
}

bool Quad::HitShadowRay(const Ray& shadowRay, Float& tMin) const
{
	return false;
}