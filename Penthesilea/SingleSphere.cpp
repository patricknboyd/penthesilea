#include "stdafx.h"

SingleSphere::SingleSphere(World* world)
	: ITracer(world)
{}

RGBColour SingleSphere::TraceRay(const Ray& ray) const
{
	double t;
	TraceResult result(*world);

	if (world->TestSphere.Hit(ray, t, result))
	{
		return Colours::Red;
	}
	else
	{
		return Colours::Black;
	}
}