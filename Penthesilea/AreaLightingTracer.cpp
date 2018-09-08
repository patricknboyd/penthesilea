#include "stdafx.h"

AreaLightingTracer::AreaLightingTracer()
	: ITracer()
{}

AreaLightingTracer::AreaLightingTracer(World* world)
	: ITracer(world)
{}

RGBColour AreaLightingTracer::TraceRay(const Ray& ray) const
{
	throw "Not yet implemented.";
}

RGBColour AreaLightingTracer::TraceRay(const Ray& ray, const int depth) const
{
	return TraceRay(ray);
}

RGBColour AreaLightingTracer::TraceRay(const Ray& ray, const int depth, Float& tMin) const
{
	return TraceRay(ray);
}