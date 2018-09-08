#pragma once
#include "stdafx.h"

class Point2D
{
public:

	Float X;
	Float Y;

	Point2D() { X = 0.0; Y = 0.0; }
	Point2D(Float x, Float y) { X = x; Y = y; }

	friend Point2D operator* (const Float& lhs, const Point2D& rhs)
	{
		return Point2D(rhs.X * lhs, rhs.Y * lhs);
	}

	friend Point2D operator* (const Point2D& lhs, const Float& rhs)
	{
		return rhs * lhs;
	}
};
