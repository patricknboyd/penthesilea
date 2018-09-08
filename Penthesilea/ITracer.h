#pragma once
#include "stdafx.h"

class World;

class ITracer
{
public:
	ITracer();
	ITracer(World* world);

	virtual RGBColour TraceRay(const Ray& ray) const;
	virtual RGBColour TraceRay(const Ray& ray, const int depth) const;
	virtual RGBColour TraceRay(const Ray& ray, const int depth, Float& tMin) const;

protected:
	World* world;
};