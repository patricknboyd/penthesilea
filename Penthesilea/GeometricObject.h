#pragma once
#include "stdafx.h"

/// <summary>
/// Represents the base class for all objects that will be rendered in a scene.
/// </summary>
/// <remarks>
/// If the lighting seems off on the back faces of objects. See Section 14.6 about reversing normals of vectors.
/// I haven't implemented it yet.
/// </remarks>
class GeometricObject
{
public:

	GeometricObject() { }
	GeometricObject(const GeometricObject&) = delete;
	GeometricObject& operator=(const GeometricObject&) = delete;

	~GeometricObject();

	virtual bool Hit(const Ray& ray, Float& tMin, class TraceResult& sr) const = 0;
	virtual bool HitShadowRay(const Ray& ray, Float& tMin) const = 0;

	RGBColour GetColour() { return Colour; }
	void SetColour(RGBColour colour) { Colour = colour; }

	IMaterial* GetMaterial() const { return material; }
	void SetMaterial(IMaterial* mat) { material = mat; }

protected:

	// This is a temporary measure until we get materials working.
	RGBColour Colour;
	/// <summary>
	/// The material used to shade this object.
	/// </summary>
	/// <remarks>
	/// Make sure that this is disposed. Currently this class doesn't have a destructor.
	/// </remarks>
	IMaterial* material;
};