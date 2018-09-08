#pragma once
#include "stdafx.h"

class OrthographicCamera : public ICamera
{
public:

	OrthographicCamera();
	OrthographicCamera(Vector3 eyePosition, Vector3 lookAtPosition, Vector3 upVector);

	void RenderScene(const class World& world);
};