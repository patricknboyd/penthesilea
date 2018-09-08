#pragma once
#include "stdafx.h"


class TraceResult
{
public:
	/// <summary>
	/// true, if the ray hit an object, otherwise false.
	/// </summary>
	bool HitDetected;
	/// <summary>
	/// The material of the nearest hit object.
	/// </summary>
	IMaterial* Material;
	/// <summary>
	/// World coordinates of hit point.
	/// </summary>
	Vector3 HitPoint;
	/// <summary>
	/// Object space coordinates of hit object. (Book says: for attaching textures to object.)
	/// </summary>
	Vector3 LocalHitPoint;
	/// <summary>
	/// Normal at hit point.
	/// </summary>
	Vector3 Normal;
	// Temporary measure until materials are implemented.
	RGBColour Colour;
	/// <summary>
	/// Ray used for specular highlights.
	/// </summary>
	Ray Ray;
	/// <summary>
	/// Recursion depth.
	/// </summary>
	int Depth;
	/// <summary>
	/// From book: "for area lights"
	/// </summary>
	Vector3 Direction;
	/// <summary>
	/// Reference to the world object.
	/// </summary>
	World& WorldRef;

	/// <summary>
	/// Gets the parametric value for the ray to the hit object.
	/// </summary>
	/// <remarks>
	/// i.e.) The hit point is Origin + (T * Direction)
	/// </remarks>
	Float T;

	TraceResult(World& world);
	~TraceResult();

	//TraceResult& operator= (const TraceResult& rhs);

};
