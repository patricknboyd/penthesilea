#include "stdafx.h"

ITracer::ITracer()
	: world(nullptr)
{}

ITracer::ITracer(World* world)
	: world(world)
{}

RGBColour ITracer::TraceRay(const Ray& ray) const
{
	return Colours::Black;
}

RGBColour ITracer::TraceRay(const Ray& ray, const int depth) const
{
	return Colours::Black;
}

RGBColour ITracer::TraceRay(const Ray& ray, const int depth, Float& tMin) const
{
	return Colours::Black;
}