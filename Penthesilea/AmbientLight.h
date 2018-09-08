#pragma once
#include "stdafx.h"

/// <summary>
/// Ambient lights provide a base level of illumination to every surface in a scene.
/// </summary>
class AmbientLight : public ILight
{
public:

	AmbientLight();

	/// <summary>
	/// Gets the intensity of the light.
	/// </summary>
	Float GetIntensity() const { return intensity; }
	/// <summary>
	/// Sets the intensity of the light.
	/// </summary>
	/// <param name="value">The new intensity value, will be clamped to the range [0.0, 1.0].</param>
	void SetIntensity(Float value) { intensity = value > 1.0 ? 1.0 : (value < 0.0 ? 0.0 : value); }

	/// <summary>
	/// Gets the light colour for this source.
	/// </summary>
	RGBColour GetColour() const { return colour; }
	/// <summary>
	/// Sets the light colour;
	/// </summary>
	void SetColour(RGBColour value) { colour = value; }
	/// <summary>
	/// Sets the light colour;
	/// </summary>
	void SetColour(Float r, Float g, Float b) { colour = RGBColour(r, g, b); }

	virtual Vector3 GetLightDirection(TraceResult& trace);
	virtual RGBColour GetRadiance(TraceResult& trace);

	virtual bool IsInShadow(const Ray& ray, const TraceResult& result) const;

private:

	Float intensity;
	RGBColour colour;

};