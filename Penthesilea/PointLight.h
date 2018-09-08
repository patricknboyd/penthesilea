#pragma once
#include "stdafx.h"

/// <summary>
/// Point lights provide illumination originating from a specified point.
/// </summary>
class PointLight : public ILight
{
public:

	/// <summary>
	/// Creates a new, white coloured point light at the origin with intensity of 1.0.
	/// </summary>
	PointLight();
	/// <summary>
	/// Creates a new, white coloured point light at the specified position, with intensity of 1.0.
	/// </summary>
	/// <param name="pos">The position to create the point light.</param>
	PointLight(Vector3 pos);

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
	/// Gets the position of the point light source.
	/// </summary>
	Vector3 GetPosition() const { return position; }
	/// <summary>
	/// Sets the position of the point light source.
	/// </summary>
	void SetPosition(Vector3 value) { position = value; }
	/// <summary>
	/// Sets the position of the point light source.
	/// </summary>
	void SetPosition(Float x, Float y, Float z) { position = Vector3(x, y, z); }

	virtual Vector3 GetLightDirection(TraceResult& trace);
	virtual RGBColour GetRadiance(TraceResult& trace);

	virtual bool IsInShadow(const Ray& ray, const TraceResult& result) const;

private:

	Float intensity;
	RGBColour colour;
	Vector3 position;

};