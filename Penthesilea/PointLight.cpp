#include "stdafx.h"

PointLight::PointLight()
	: PointLight(Vector3::Zero)
{}

PointLight::PointLight(Vector3 pos)
{
	position = pos;
	colour = Colours::White;
	intensity = 1.0;
}

Vector3 PointLight::GetLightDirection(TraceResult& trace)
{
	return Vector3::Normalize(position - trace.LocalHitPoint);
}

RGBColour PointLight::GetRadiance(TraceResult& result)
{
	return intensity * colour;
}

bool PointLight::IsInShadow(const Ray& ray, const TraceResult& trace) const
{
	Float t;
	int nObjects = trace.WorldRef.GetWorldObjectCount();
	Float lightDistance = Vector3::Distance(position, ray.Origin);

	for (int i = 0; i < nObjects; i++)
	{
		GeometricObject* object = trace.WorldRef.GetWorldObject(i);

		if (object->HitShadowRay(ray, t) && t < lightDistance)
		{
			return true;
		}
	}

	return false;
}