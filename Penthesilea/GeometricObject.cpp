#include "stdafx.h"

GeometricObject::~GeometricObject()
{
	if (material)
	{
		delete material;
		material = nullptr;
	}
}