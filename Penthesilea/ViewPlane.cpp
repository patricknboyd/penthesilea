#include "stdafx.h"

ViewPlane::ViewPlane()
{
	SetHorizontalResolution(200);
	SetVerticalResolution(200);
	SetPixelSize(1.0);
	SetGamma(1.0);
	sampler = nullptr;
}

ViewPlane::ViewPlane(int hRes, int vRes, Float pixelSize, Float gamma)
{
	SetHorizontalResolution(hRes);
	SetVerticalResolution(vRes);
	SetPixelSize(pixelSize);
	SetGamma(gamma);

	sampler = nullptr;
}

Gdiplus::Color ViewPlane::GetScreenColour(const RGBColour& colour) const
{

	if (_gamma != 1.0)
	{
		Gdiplus::Color c((BYTE)(pow(colour.R, _inverseGamma) * 255.0), (BYTE)(pow(colour.G, _inverseGamma) * 255.0), (BYTE)(pow(colour.B, _inverseGamma) * 255.0));
		return c;
	}
	else
	{
		Gdiplus::Color c((BYTE)(colour.R * 255.0), (BYTE)(colour.G * 255.0), (BYTE)(colour.B * 255.0));
		return c;
	}

	
}

void ViewPlane::SetSampler(ISampler* newSampler)
{
	if (sampler)
	{
		delete sampler;
	}

	sampler = newSampler;
	samples = sampler->GetSampleCount();
}

void ViewPlane::SetSampleCount(const int count)
{
	samples = count;

	if (sampler)
	{
		delete sampler;
	}

	if (count > 1)
	{
		sampler = new MultiJitteredSampler(count);
	}
	else
	{
		sampler = new RegularSampler();
	}

}

ViewPlane::~ViewPlane()
{
	if (sampler)
	{
		delete sampler;
		sampler = nullptr;
	}
}
