#include "stdafx.h"

DirectionalLight::DirectionalLight()
	: DirectionalLight(Vector3::Forward)
{
	enableShadows = false;
}

DirectionalLight::DirectionalLight(Vector3 dir)
{
	direction = dir;
	colour = Colours::White;
	intensity = 1.0;
}

Vector3 DirectionalLight::GetLightDirection(TraceResult& trace)
{
	return direction;
}

RGBColour DirectionalLight::GetRadiance(TraceResult& trace)
{
	return intensity * colour;
}

bool DirectionalLight::IsInShadow(const Ray& ray, const TraceResult& result) const
{
	throw "Not Yet Implemented";
}