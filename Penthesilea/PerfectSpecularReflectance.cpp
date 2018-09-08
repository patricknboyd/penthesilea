#include "stdafx.h"

PerfectSpecularReflectance::PerfectSpecularReflectance()
	: PerfectSpecularReflectance(nullptr)
{
}

PerfectSpecularReflectance::PerfectSpecularReflectance(ISampler* sampler)
	: IReflectanceFunction(sampler)
{

}

RGBColour PerfectSpecularReflectance::Calculate(const TraceResult & result, const Vector3 & incoming, const Vector3 outgoing) const
{
	return Colours::Black;
}

RGBColour PerfectSpecularReflectance::GetReflectionAngle(const TraceResult & result, Vector3 & incoming, const Vector3 & outgoing) const
{
	throw "Not yet implemented. (Chapter 24)";
}

RGBColour PerfectSpecularReflectance::HemisphericalReflectance(const TraceResult & result, const Vector3 & outgoing) const
{
	return Colours::Black;
}

