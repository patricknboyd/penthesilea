#include "stdafx.h"

MatteMaterial::MatteMaterial()
	: IMaterial(),
	ambientFunction(new LambertianReflectance),
	diffuseFunction(new LambertianReflectance)
{

}

void MatteMaterial::SetAmbientIntensity(Float intensity)
{
	ambientFunction->SetReflectionCoefficient(intensity);
}

void MatteMaterial::SetDiffuseIntensity(Float intensity)
{
	diffuseFunction->SetReflectionCoefficient(intensity);
}

void MatteMaterial::SetColour(RGBColour colour)
{
	ambientFunction->SetColour(colour);
	diffuseFunction->SetColour(colour);
}

void MatteMaterial::SetColour(Float r, Float g, Float b)
{
	ambientFunction->SetColour(r, g, b);
	diffuseFunction->SetColour(r, g, b);
}

RGBColour MatteMaterial::Shade(TraceResult& trace)
{
	Vector3 outgoingDir = -trace.Ray.Direction;
	RGBColour radiance = ambientFunction->HemisphericalReflectance(trace, outgoingDir)
		* trace.WorldRef.GetAmbientLight()->GetRadiance(trace);

	unsigned int nLights = trace.WorldRef.GetLightCount();

	for (unsigned int i = 0; i < nLights; i++)
	{
		ILight* light = trace.WorldRef.GetLight(i);

		Vector3 incomingDir = light->GetLightDirection(trace);
		Float lightAngle = Vector3::Dot(trace.Normal, incomingDir);

		if (lightAngle > 0.0)
		{
			// The book has the incoming and outgoing angles reversed here...
			radiance += diffuseFunction->Calculate(trace, incomingDir, outgoingDir)
				* light->GetRadiance(trace) * lightAngle;
		}
	}

	return radiance;
}

MatteMaterial::~MatteMaterial()
{
	if (ambientFunction)
	{
		delete ambientFunction;
		ambientFunction = nullptr;
	}

	if (diffuseFunction)
	{
		delete diffuseFunction;
		diffuseFunction = nullptr;
	}
}