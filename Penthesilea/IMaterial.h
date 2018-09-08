#pragma once
#include "stdafx.h"

class IMaterial
{
public:

	IMaterial();
	IMaterial(const IMaterial&) = delete;
	virtual ~IMaterial();

	IMaterial& operator=(const IMaterial&) = delete;

	virtual RGBColour Shade(TraceResult& trace);
	virtual RGBColour AreaLightShade(TraceResult& trace);
	virtual RGBColour WhittedShade(TraceResult& trace);
	virtual RGBColour PathShade(TraceResult& trace);

private:

};
