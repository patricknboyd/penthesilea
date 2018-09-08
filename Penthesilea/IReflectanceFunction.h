#pragma once
#include "stdafx.h"

class TraceResult;

// Represents the base class for functions to calculate how light reflects off of surfaces.
// Materials will use one or more of these to determine how a surface should be lit.
// Calculations are done by using Bidirectional Reflectance Distribution Functions (BRDFs).
class IReflectanceFunction
{
public:

	IReflectanceFunction() { this->sampler = nullptr; }
	IReflectanceFunction(ISampler* sampler) { this->sampler = sampler; }

	// Calculates the value of the BRDF. Corresponds to the "f" function.
	virtual RGBColour Calculate(const TraceResult& result, const Vector3& incoming, const Vector3 outgoing) const = 0;

	// Calculate the direction of reflected rays. Corresponds to the "sample_f" function.
	virtual RGBColour GetReflectionAngle(const TraceResult& result, Vector3& incoming, const Vector3& outgoing) const = 0;

	// Returns the bihemispherical reflectance. Corresponds to the "rho" function.
	virtual RGBColour HemisphericalReflectance(const TraceResult& result, const Vector3& outgoing) const = 0;

	void SetSampler(ISampler* sampler) { std::cout << "Setting reflectance function sampler.";  this->sampler = sampler; }

protected:

	ISampler* sampler;
};
