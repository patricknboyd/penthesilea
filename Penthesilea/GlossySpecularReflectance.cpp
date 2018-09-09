#include "stdafx.h"

GlossySpecularReflectance::GlossySpecularReflectance()
	: GlossySpecularReflectance(nullptr)
{}

GlossySpecularReflectance::GlossySpecularReflectance(ISampler* sampler)
	: IReflectanceFunction(sampler)
{
	phongExponent = 20.0;
	specularCoefficient = 0.25;
}

RGBColour GlossySpecularReflectance::Calculate(const TraceResult & result, const Vector3 & incoming, const Vector3 outgoing) const
{
	Float incidenceDotProduct = Vector3::Dot(result.Normal, incoming);
	Vector3 reflected(-incoming + 2.0 * result.Normal * incidenceDotProduct);
	Float outgoingDotProduct = Vector3::Dot(reflected, outgoing);

	if (outgoingDotProduct > 0.0)
	{
		Float value = specularCoefficient * pow(outgoingDotProduct, phongExponent);
		return RGBColour(value, value, value);
	}
	else
	{
		return Colours::Black;
	}
}

RGBColour GlossySpecularReflectance::GetReflectionAngle(const TraceResult & result, Vector3 & incoming, const Vector3 & outgoing) const
{
	throw "Not yet implemented. (Chapter 25)";
}

RGBColour GlossySpecularReflectance::HemisphericalReflectance(const TraceResult & result, const Vector3 & outgoing) const
{
	return Colours::Black;
}

