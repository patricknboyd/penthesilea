#pragma once
#include "stdafx.h"

class Vector3
{
public:

	static const Vector3 Zero;
	static const Vector3 Up;
	static const Vector3 Forward;
	static const Vector3 Right;

	Vector3();
	Vector3(Float x, Float y, Float z);

	Float X;
	Float Y;
	Float Z;

	Float Length() const;

	static Float Dot(const Vector3& a, const Vector3& b);
	Float Dot(const Vector3& other) const;

	static Vector3 Cross(const Vector3& a, const Vector3& b);
	Vector3 Cross(const Vector3& other)const ;

	static Vector3 Normalize(const Vector3& vec);
	Vector3 Normalize() const;

	static Float Distance(const Vector3& a, const Vector3& b);
	Float Distance(const Vector3& other) const;

	Vector3 operator+ (const Vector3& other) const;
	Vector3 operator- (const Vector3& other) const;
	//Vector3 operator* (Float& factor) const;
	//Vector3 operator/ (Float& denominator) const;

	friend Vector3 operator* (const Float& lhs, Vector3 rhs)
	{
		return Vector3(rhs.X * lhs, rhs.Y * lhs, rhs.Z * lhs);
	}

	friend Vector3 operator* (const Vector3 lhs, const Float& rhs)
	{
		return Vector3(lhs.X * rhs, lhs.Y * rhs, lhs.Z * rhs);
	}

	friend Vector3 operator/ (const Vector3& lhs, const Float& rhs)
	{
		return Vector3(lhs.X / rhs, lhs.Y / rhs, lhs.Z / rhs);
	}

	friend Vector3 operator- (const Vector3& vec)
	{
		return Vector3(-vec.X, -vec.Y, -vec.Z);
	}

	friend std::ostream& operator<< (std::ostream& stream, const Vector3& v)
	{
		return stream << "(" << v.X << ", " << v.Y << ", " << v.Z << ")";
	}



private:


};