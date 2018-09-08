#include "stdafx.h"

PathTracer::PathTracer()
	: ITracer()
{}

PathTracer::PathTracer(World* world)
	: ITracer(world)
{}

RGBColour PathTracer::TraceRay(const Ray& ray) const
{
	throw "Not yet implemented.";
}

RGBColour PathTracer::TraceRay(const Ray& ray, const int depth) const
{
	return TraceRay(ray);
}

RGBColour PathTracer::TraceRay(const Ray& ray, const int depth, Float& tMin) const
{
	return TraceRay(ray);
}