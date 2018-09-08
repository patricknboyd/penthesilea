#include "stdafx.h"

MultipleObjects::MultipleObjects(World* world)
	: ITracer(world)
{
}

RGBColour MultipleObjects::TraceRay(const Ray& ray, const int depth) const
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