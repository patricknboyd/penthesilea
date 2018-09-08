#pragma once
#include "stdafx.h"

class SingleSphere : public ITracer
{
public:
	SingleSphere(World* world);
	virtual RGBColour TraceRay(const Ray& ray) const;
};