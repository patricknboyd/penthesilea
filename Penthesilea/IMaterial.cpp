#include "stdafx.h"

IMaterial::IMaterial()
{

}

RGBColour IMaterial::Shade(TraceResult& trace)
{
	return Colours::Black;
}

RGBColour IMaterial::WhittedShade(TraceResult& trace)
{
	return Colours::Black;
}

RGBColour IMaterial::AreaLightShade(TraceResult& trace)
{
	return Colours::Black;
}

RGBColour IMaterial::PathShade(TraceResult& trace)
{
	return Colours::Black;
}

IMaterial::~IMaterial()
{
	// The base class doesn't do anything with this, but derived classes will.
}