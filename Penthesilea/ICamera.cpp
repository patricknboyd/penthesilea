#include "stdafx.h"

ICamera::ICamera()
	: ICamera(Vector3::Zero, Vector3(0.0, 0.0, -10.0), Vector3::Up)
{
}

ICamera::ICamera(Vector3 eyePosition, Vector3 lookAtPosition, Vector3 upVector)
{
	position = eyePosition;
	lookAt = lookAtPosition;
	up = upVector;

	exposureTime = 1.0f;

	CalculateLocalCoordinateBase();
}

void ICamera::CalculateLocalCoordinateBase()
{
	w = Vector3::Normalize(position - lookAt);
	u = Vector3::Normalize(Vector3::Cross(up, w));
	v = Vector3::Cross(w, u);
}