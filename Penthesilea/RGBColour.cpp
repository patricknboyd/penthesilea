#include "stdafx.h"

RGBColour::RGBColour()
{
	R = 0.0;
	G = 0.0;
	B = 0.0;
}

RGBColour::RGBColour(Float r, Float g, Float b)
{
	R = r;
	G = g;
	B = b;
}

RGBColour::RGBColour(const RGBColour& c)
{
	R = c.R;
	G = c.G;
	B = c.B;
}

const RGBColour Colours::Black =	RGBColour(0.0, 0.0, 0.0);
const RGBColour Colours::Gray =		RGBColour(0.5, 0.5, 0.5);
const RGBColour Colours::White =	RGBColour(1.0, 1.0, 1.0);
const RGBColour Colours::Red =		RGBColour(1.0, 0.0, 0.0);
const RGBColour Colours::Green =	RGBColour(0.0, 1.0, 0.0);
const RGBColour Colours::Blue =		RGBColour(0.0, 0.0, 1.0);
const RGBColour Colours::Cyan =		RGBColour(0.0, 1.0, 1.0);
const RGBColour Colours::Yellow =	RGBColour(1.0, 1.0, 0.0);
const RGBColour Colours::Magenta =	RGBColour(1.0, 0.0, 1.0);
const RGBColour Colours::HotPink =	RGBColour(1.0, 0.412, 0.706);
