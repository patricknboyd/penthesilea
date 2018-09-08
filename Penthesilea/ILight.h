#pragma once
#include "stdafx.h"

class Ray;

/// <summary>
/// Represents the base class for all light objects.
/// </summary>
class ILight
{
public:

	ILight()
		: enableShadows(true)
	{}

	/// <summary>
	/// Gets the direction of the incoming light at a hit point.
	/// </summary>
	/// <param name="trace">The current trace results.</param>
	/// <returns>A vector3 pointing in the direction of the light.</returns>
	virtual Vector3 GetLightDirection(TraceResult& trace) = 0;
	/// <summary>
	/// Gets the incident radiance at a hit point.
	/// </summary>
	/// <param name="trace">The current trace results.</param>
	/// <returns>A colour reprsenting the radiance of the light at the hit point.</returns>
	virtual RGBColour GetRadiance(TraceResult& trace) = 0;

	/// <summary>
	/// Traces a shadow ray against objects in the scene to determine if it is in shadow for this light.
	/// </summary>
	/// <param name="shadowRay">The ray from the hit point being tested to the light.</param>
	/// <param name="trace">Trace information for the current pixel.</param>
	/// <remarks>
	/// I.E. Can this light see the ray origin. 
	/// TODO: Should the caller just pass its position and leave it to this function to calculate the ray?
	/// </remarks>
	/// <returns></returns>
	virtual bool IsInShadow(const Ray& shadowRay, const TraceResult& trace) const = 0;

	/// <summary>
	/// Gets whether shadows are enabled for this light.
	/// </summary>
	/// <returns>true, if shadows are enabled, otherwise false.</returns>
	bool GetShadowsEnabled() const { return enableShadows; }

	/// <summary>
	/// Turns shadows on for this light source.
	/// </summary>
	void EnableShadows() { enableShadows = true; }
	/// <summary>
	/// Turns shadows off for this light source.
	/// </summary>
	void DisableShadows() { enableShadows = false; }

protected:

	bool enableShadows;
};
