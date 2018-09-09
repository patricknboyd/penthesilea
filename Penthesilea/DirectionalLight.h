#pragma once
#include "stdafx.h"

/// <summary>
/// Directional lights apply parallel light rays of equal intensity to the entire scene.
/// </summary>
class DirectionalLight : public ILight
{
public:

	/// <summary>
	/// Creates a new directional light pointing along the negatize z-axis.
	/// </summary>
	DirectionalLight();
	/// <summary>
	/// Creates a new directional light with the speciied direction.
	/// </summary>
	/// <param name="dir">The direction the light is pointing.</param>
	DirectionalLight(Vector3 dir);

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

	/// <summary>
	/// Gets the direction of the light coming from this source.
	/// </summary>
	Vector3 GetDirection() const { return direction; }
	/// <summary>
	/// Sets the direction of the light from this source. The direction vector will be normalized.
	/// </summary>
	/// <param name="value">The vector direction, this will be normalized.</param>
	void SetDirection(Vector3 value) { direction = Vector3::Normalize(value); }
	/// <summary>
	/// Sets the direction of the light from this source. The direction vector will be normalized.
	/// </summary>
	/// <param name="x">The x component of the light direction.</param>
	/// <param name="y">The y component of the light direction.</param>
	/// <param name="z">The z component of the light direction.</param>
	void SetDirection(Float x, Float y, Float z) { direction = Vector3::Normalize(Vector3(x, y, z)); }

	virtual Vector3 GetLightDirection(TraceResult& trace);
	virtual RGBColour GetRadiance(TraceResult& trace);

	virtual bool IsInShadow(const Ray& ray, const TraceResult& result) const;

private:

	Float intensity;
	RGBColour colour;
	Vector3 direction;

};