#pragma once
#include "stdafx.h"

// Represents a simple perspective camera.
class PinholeCamera : public ICamera
{
public:

	PinholeCamera();
	PinholeCamera(Vector3 eyePosition, Vector3 lookAtPosition, Vector3 upVector, Float distanceToViewPlane);

	void RenderScene(const class World& world);

	// Gets the distance from the camera eye to the view plane.
	Float GetViewPlaneDistance() const { return viewPlaneDistance; }
	// Gets the amount of zoom applied by the camera.
	Float GetZoomFactor() const { return zoomFactor; }
	// Sets the amount of zoom applied by the camera.
	void SetZoomFactor(Float value) { zoomFactor = value; }

private:

	// The distance between the eye position and the view plane.
	Float viewPlaneDistance;
	Float zoomFactor;

	Vector3 GetRayDirection(const Point2D& sourcePoint) const;
};
