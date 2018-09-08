#pragma once
#include "stdafx.h"

class RGBColour
{
public:

	RGBColour();
	RGBColour(Float r, Float g, Float b);
	RGBColour(const RGBColour& c);

	Float R;
	Float G;
	Float B;

	friend RGBColour operator+ (const RGBColour& lhs, const RGBColour& rhs)
	{
		return RGBColour(lhs.R + rhs.R, lhs.G + rhs.G, lhs.B + rhs.B);
	}

	friend RGBColour operator* (const RGBColour& lhs, const RGBColour& rhs)
	{
		return RGBColour(lhs.R * rhs.R, lhs.G * rhs.G, lhs.B * rhs.B);
	}

	friend RGBColour operator/ (const RGBColour& lhs, const Float& rhs)
	{
		return RGBColour(lhs.R / rhs, lhs.G / rhs, lhs.B / rhs);
	}

	friend RGBColour operator* (const RGBColour& lhs, const Float& rhs)
	{
		return RGBColour(lhs.R * rhs, lhs.G * rhs, lhs.B * rhs);

	}

	friend RGBColour operator* (const Float& lhs, const RGBColour& rhs)
	{
		return rhs * lhs;
	}
		

	RGBColour& operator+= (const RGBColour& rhs)
	{
		this->R += rhs.R;
		this->G += rhs.G;
		this->B += rhs.B;

		return *this;
	}


};

class Colours
{
public:
	static const RGBColour Black;
	static const RGBColour Gray;
	static const RGBColour White;
	static const RGBColour Red;
	static const RGBColour Blue;
	static const RGBColour Green;
	static const RGBColour Cyan;
	static const RGBColour Yellow;
	static const RGBColour Magenta;
	static const RGBColour HotPink;
};

