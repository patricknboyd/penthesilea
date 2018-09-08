#include "stdafx.h"

WhittedTracer::WhittedTracer()
	: ITracer()
{}

WhittedTracer::WhittedTracer(World* world)
	: ITracer(world)
{}

RGBColour WhittedTracer::TraceRay(const Ray& ray) const
{
	throw "Not yet implemented.";
}

RGBColour WhittedTracer::TraceRay(const Ray& ray, const int depth) const
{
	return TraceRay(ray);
}

RGBColour WhittedTracer::TraceRay(const Ray& ray, const int depth, Float& tMin) const
{
	return TraceRay(ray);
}