#include "stdafx.h"

const Float Triangle::kEpsilon = 0.001;

Triangle::Triangle()
	: Triangle(Vector3(0.0, 0.0, 0.0), Vector3(1.0, 0.0, 0.0), Vector3(0.0, 1.0, 0.0))
{}

Triangle::Triangle(Vector3 vertex1, Vector3 vertex2, Vector3 vertex3)
{
	v0 = vertex1;
	v1 = vertex2;
	v2 = vertex3;

	CalculateNormal();
}

bool Triangle::Hit(const Ray& ray, Float& tMin, TraceResult& result) const
{
	double a = v0.X - v1.X, b = v0.X - v2.X, c = ray.Direction.X, d = v0.X - ray.Origin.X;
	double e = v0.Y - v1.Y, f = v0.Y - v2.Y, g = ray.Direction.Y, h = v0.Y - ray.Origin.Y;
	double i = v0.Z - v1.Z, j = v0.Z - v2.Z, k = ray.Direction.Z, l = v0.Z - ray.Origin.Z;

	double m = f * k - g * j, n = h * k - g * l, p = f * l - h * j;
	double q = g * i - e * k, s = e * j - f * i;

	double inv_denom = 1.0 / (a * m + b * q + c * s);

	double e1 = d * m - b * n - c * p;
	double beta = e1 * inv_denom;

	if (beta < 0.0)
		return (false);

	double r = r = e * l - h * i;
	double e2 = a * n + d * q + c * r;
	double gamma = e2 * inv_denom;

	if (gamma < 0.0)
		return (false);

	if (beta + gamma > 1.0)
		return (false);

	double e3 = a * p - b * r + d * s;
	double t = e3 * inv_denom;

	if (t < kEpsilon)
		return (false);

	tMin = t;
	result.Normal = normal;
	result.LocalHitPoint = ray.Origin + t * ray.Direction;

	return (true);
}

bool Triangle::HitShadowRay(const Ray& shadowRay, Float& tMin) const
{
	return false;
}

void Triangle::CalculateNormal()
{
	normal = Vector3::Cross(v2 - v0, v1 - v0);
}