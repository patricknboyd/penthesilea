#pragma once
#include "stdafx.h"

class LambertianReflectance : public IReflectanceFunction
{
public:

	LambertianReflectance();
	LambertianReflectance(ISampler* sampler);

	virtual RGBColour Calculate(const TraceResult& result, const Vector3& incoming, const Vector3 outgoing) const;
	virtual RGBColour GetReflectionAngle(const TraceResult& result, Vector3& incoming, const Vector3& outgoing) const;
	virtual RGBColour HemisphericalReflectance(const TraceResult& result, const Vector3& outgoing) const;

	Float GetReflectionCoefficient() const { return reflectionCoefficient; }
	void SetReflectionCoefficient(Float value) { reflectionCoefficient = value; }

	RGBColour GetColour() const { return colour; }
	void SetColour(RGBColour value) { colour = value; }
	void SetColour(Float r, Float g, Float b) { colour = RGBColour(r, g, b); }

private:

	Float reflectionCoefficient;
	RGBColour colour;
};