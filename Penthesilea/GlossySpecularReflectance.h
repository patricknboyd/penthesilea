#pragma once
#include "stdafx.h"

/// <summary>
/// Reflectance functions for glossy surfaces. Produces an effect similar to shiny plastic.
/// </summary>
class GlossySpecularReflectance : public IReflectanceFunction
{
public:

	GlossySpecularReflectance();
	GlossySpecularReflectance(ISampler* sampler);

	/// <summary>
	/// Gets the intensity of the specular reflection.
	/// </summary>
	/// <returns></returns>
	Float GetSpecularCoefficient() const { return specularCoefficient; }
	void SetSpecularCoefficient(Float value) { specularCoefficient = value; }

	/// <summary>
	/// Gets the phone exponent which controls the size of the specular reflection.
	/// </summary>
	/// <returns></returns>
	Float GetPhongExponent() const { return phongExponent; }
	void SetPhongExponent(Float value) { phongExponent = value; }

	virtual RGBColour Calculate(const TraceResult& result, const Vector3& incoming, const Vector3 outgoing) const;
	virtual RGBColour GetReflectionAngle(const TraceResult& result, Vector3& incoming, const Vector3& outgoing) const;
	virtual RGBColour HemisphericalReflectance(const TraceResult& result, const Vector3& outgoing) const;

private:

	Float specularCoefficient;
	Float phongExponent;

};