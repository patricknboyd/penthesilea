#pragma once
#include "stdafx.h"

// Base class for all cameras.
class ICamera
{
public:

	ICamera();
	ICamera(Vector3 eyePosition, Vector3 lookAtPosition, Vector3 upVector);

	virtual void RenderScene(const class World& world) = 0;

	Vector3 GetPosition() const { return position; }
	Vector3 GetLookAt() const { return lookAt; }
	Vector3 GetUp() const { return up; }

	Float GetExposureTime() const { return exposureTime; }
	void SetExposureTIme(Float value) { exposureTime = value; }

protected:

	Vector3 position;
	Vector3 lookAt;
	Vector3 up;

	Vector3 u, v, w;
	Float exposureTime;

private:

	void CalculateLocalCoordinateBase();
};
