#pragma once
#include "stdafx.h"

class RayCastTracer : public ITracer
{
public:

	RayCastTracer();
	RayCastTracer(World* world);

	virtual RGBColour TraceRay(const Ray& ray) const;
	virtual RGBColour TraceRay(const Ray& ray, const int depth) const;
	virtual RGBColour TraceRay(const Ray& ray, const int depth, Float& tMin) const;

private:


};