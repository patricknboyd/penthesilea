#include "stdafx.h"

AmbientLight::AmbientLight()
{
	colour = Colours::White;
	intensity = 0.2;
	enableShadows = false;
}

Vector3 AmbientLight::GetLightDirection(TraceResult& trace)
{
	return Vector3::Zero;
}

RGBColour AmbientLight::GetRadiance(TraceResult& trace)
{
	return intensity * colour;
}

bool AmbientLight::IsInShadow(const Ray& ray, const TraceResult& result) const
{
	return false;
}