#pragma once
#include "stdafx.h"

class ViewPlane
{
public:

	ViewPlane();
	ViewPlane(int hRes, int vRes, Float pixelSize, Float gamma);
	~ViewPlane();

	// Removed unused implicit functions.
	ViewPlane(const ViewPlane&) = delete;
	ViewPlane& operator= (const ViewPlane&) = delete;

	int GetHorizontalResolution() const { return horizontalResolution; };
	void SetHorizontalResolution(int hRes) { horizontalResolution = hRes; }

	int GetVerticalResolution() const { return verticalResolution; };
	void SetVerticalResolution(int vRes) { verticalResolution = vRes; }

	Float GetPixelSize() const { return pixelSize; };
	void SetPixelSize(Float size) { pixelSize = size; }

	Float GetGamma() const { return _gamma; };
	Float GetInverseGamma() const { return _inverseGamma; };
	void SetGamma(Float gamma) { _gamma = gamma; _inverseGamma = 1.0 / _gamma; }

	int GetSampleCount() const { return samples; }
	void SetSampleCount(const int count);

	ISampler* GetSampler() const { return sampler; }
	void SetSampler(ISampler* newSampler);

	Gdiplus::Color GetScreenColour(const RGBColour& colour) const;

private:

	int horizontalResolution;
	int verticalResolution;
	Float pixelSize;
	Float _gamma;
	Float _inverseGamma;

	ISampler* sampler;

	int samples;
};