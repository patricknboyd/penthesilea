#include "stdafx.h"

LambertianReflectance::LambertianReflectance()
	: LambertianReflectance(nullptr)
{

}

LambertianReflectance::LambertianReflectance(ISampler* sampler)
	: IReflectanceFunction(sampler)
{
	reflectionCoefficient = 1.0;
	// Initialize this to a nice garish colour, as a reminder to initialze this value.
	colour = Colours::HotPink;
}

RGBColour LambertianReflectance::Calculate(const TraceResult & result, const Vector3 & incoming, const Vector3 outgoing) const
{
	return reflectionCoefficient * INV_PI * colour;
}

RGBColour LambertianReflectance::GetReflectionAngle(const TraceResult & result, Vector3 & incoming, const Vector3 & outgoing) const
{
	throw "Not yet implemented. (Chapter 26)";
}

RGBColour LambertianReflectance::HemisphericalReflectance(const TraceResult & result, const Vector3 & outgoing) const
{
	return reflectionCoefficient * colour;
}

