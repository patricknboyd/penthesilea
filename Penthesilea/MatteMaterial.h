#pragma once
#include "stdafx.h"

class MatteMaterial : public IMaterial
{
public:

	MatteMaterial();
	MatteMaterial(const MatteMaterial&) = delete;
	virtual ~MatteMaterial();

	MatteMaterial& operator= (const MatteMaterial&) = delete;

	virtual RGBColour Shade(TraceResult& trace);

	void SetAmbientIntensity(Float intensity);
	void SetDiffuseIntensity(Float intensity);
	void SetColour(RGBColour colour);
	void SetColour(Float r, Float g, Float b);

private:

	LambertianReflectance* ambientFunction;
	LambertianReflectance* diffuseFunction;


};
