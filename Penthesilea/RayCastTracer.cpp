#include "stdafx.h"

RayCastTracer::RayCastTracer()
	: ITracer()
{}

RayCastTracer::RayCastTracer(World* world)
	: ITracer(world)
{}

RGBColour RayCastTracer::TraceRay(const Ray& ray) const
{
	TraceResult tr(world->HitObjects(ray));

	if (tr.HitDetected)
	{
		tr.Ray = ray;
		return tr.Material->Shade(tr);
	}
	else
	{
		return world->BackgroundColour;
	}
}

RGBColour RayCastTracer::TraceRay(const Ray& ray, const int depth) const
{
	return TraceRay(ray);
}

RGBColour RayCastTracer::TraceRay(const Ray& ray, const int depth, Float& tMin) const
{
	return TraceRay(ray);
}