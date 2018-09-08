#include "stdafx.h"

const Float Sphere::kEpsilon = 0.001;

Sphere::Sphere()
{
	_center = Vector3();
	_radius = 1.0;
}

Sphere::Sphere(const Vector3& center, Float radius)
{
	_center = center;
	_radius = radius;
}

bool Sphere::Hit(const Ray& ray, Float& tMin, TraceResult& result) const
{
	double t = 0.0;

	Vector3 fromCenter = ray.Origin - _center;

	// Calculate the variables for the quadratic equation
	double a = Vector3::Dot(ray.Direction, ray.Direction);
	double b = 2.0 * Vector3::Dot(fromCenter, ray.Direction);
	double c = Vector3::Dot(fromCenter, fromCenter) - (_radius * _radius);

	// Calculate the discriminant.
	double disc = b * b - (4.0 * a * c);

	if (disc < 0.0)
	{
		return false;
	}
	else
	{
		double e = sqrt(disc);
		double denom = 2.0 * a;

		// Get the first root;
		t = (-b - e) / denom;

		if (t > kEpsilon)
		{
			tMin = t;
			result.Normal = (fromCenter + (ray.Direction * t)) / _radius;
			result.LocalHitPoint = ray.Origin + (t * ray.Direction);
			return true;
		}

		// Check the second root;
		t = (-b + e) / denom;

		if (t > kEpsilon)
		{
			tMin = t;
			result.Normal = (fromCenter + (ray.Direction * t)) / _radius;
			result.LocalHitPoint = ray.Origin + (t * ray.Direction);
			return true;
		}
	}

	return false;
}

bool Sphere::HitShadowRay(const Ray& ray, Float& tMin) const
{
	double t = 0.0;

	Vector3 fromCenter = ray.Origin - _center;

	// Calculate the variables for the quadratic equation
	double a = Vector3::Dot(ray.Direction, ray.Direction);
	double b = 2.0 * Vector3::Dot(fromCenter, ray.Direction);
	double c = Vector3::Dot(fromCenter, fromCenter) - (_radius * _radius);

	// Calculate the discriminant.
	double disc = b * b - (4.0 * a * c);

	if (disc < 0.0)
	{
		return false;
	}
	else
	{
		double e = sqrt(disc);
		double denom = 2.0 * a;

		// Get the first root;
		t = (-b - e) / denom;

		if (t > kEpsilon)
		{
			tMin = t;
			return true;
		}

		// Check the second root;
		t = (-b + e) / denom;

		if (t > kEpsilon)
		{
			tMin = t;
			return true;
		}
	}

	return false;
}