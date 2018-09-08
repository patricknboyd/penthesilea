#pragma once
#include "stdafx.h"

class PerfectSpecularReflectance : public IReflectanceFunction
{
public:

	PerfectSpecularReflectance();
	PerfectSpecularReflectance(ISampler* sampler);

	virtual RGBColour Calculate(const TraceResult& result, const Vector3& incoming, const Vector3 outgoing) const;
	virtual RGBColour GetReflectionAngle(const TraceResult& result, Vector3& incoming, const Vector3& outgoing) const;
	virtual RGBColour HemisphericalReflectance(const TraceResult& result, const Vector3& outgoing) const;

};