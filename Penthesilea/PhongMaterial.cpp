#include "stdafx.h"

PhongMaterial::PhongMaterial()
	: ambient(new LambertianReflectance),
	diffuse(new LambertianReflectance),
	specular(new GlossySpecularReflectance)
{

}

void PhongMaterial::SetAmbientIntensity(Float intensity)
{
	ambient->SetReflectionCoefficient(intensity);
}

void PhongMaterial::SetDiffuseIntensity(Float intensity)
{
	diffuse->SetReflectionCoefficient(intensity);
}

void PhongMaterial::SetSpecularIntensity(Float intensity)
{
	specular->SetSpecularCoefficient(intensity);
}

void PhongMaterial::SetSpecularSharpness(Float value)
{
	specular->SetPhongExponent(value);
}

void PhongMaterial::SetColour(RGBColour colour)
{
	ambient->SetColour(colour);
	diffuse->SetColour(colour);
}

void PhongMaterial::SetColour(Float r, Float g, Float b)
{
	ambient->SetColour(r, g, b);
	diffuse->SetColour(r, g, b);
}

RGBColour PhongMaterial::Shade(TraceResult& trace)
{
	Vector3 outgoing = -trace.Ray.Direction;
	RGBColour colour = ambient->HemisphericalReflectance(trace, outgoing) * trace.WorldRef.GetAmbientLight()->GetRadiance(trace);

	unsigned int nLights = trace.WorldRef.GetLightCount();

	for (unsigned int i = 0; i < nLights; i++)
	{
		ILight* light = trace.WorldRef.GetLight(i);
		Vector3 incoming = light->GetLightDirection(trace);
		Float incomingAngle = Vector3::Dot(trace.Normal, incoming);

		if (incomingAngle > 0.0)
		{
			bool inShadow = false;

			if (light->GetShadowsEnabled())
			{
				Ray shadowRay(trace.HitPoint, incoming);
				inShadow = light->IsInShadow(shadowRay, trace);
			}

			if (!inShadow)
			{
				// Don't apply diffuse and specular lighting if the hit point is in shadow.
				colour += (diffuse->Calculate(trace, incoming, outgoing) + specular->Calculate(trace, incoming, outgoing))
					* light->GetRadiance(trace) * incomingAngle;
			}
		}
	}

	return colour;
}

PhongMaterial::~PhongMaterial()
{
	if (ambient)
	{
		delete ambient;
		ambient = nullptr;
	}
	if (diffuse)
	{
		delete diffuse;
		diffuse = nullptr;
	}
	if (specular)
	{
		delete specular;
		specular = nullptr;
	}
}