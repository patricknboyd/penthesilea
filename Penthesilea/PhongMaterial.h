#pragma once
#include "stdafx.h"

class PhongMaterial : public IMaterial
{
public:

	PhongMaterial();
	PhongMaterial(const PhongMaterial&) = delete;
	~PhongMaterial();

	PhongMaterial& operator= (const PhongMaterial&) = delete;

	virtual RGBColour Shade(TraceResult& trace);

	void SetAmbientIntensity(Float intensity);
	void SetDiffuseIntensity(Float intensity);
	void SetSpecularIntensity(Float intensity);
	void SetColour(RGBColour colour);
	void SetColour(Float r, Float g, Float b);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="value"></param>
	void SetSpecularSharpness(Float value);

protected:

	LambertianReflectance* ambient;
	LambertianReflectance* diffuse;
	GlossySpecularReflectance* specular;


};
