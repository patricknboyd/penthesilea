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

	inline static Float Dot(const Vector3& a, const Vector3& b)
	{
		return (a.X * b.X) + (a.Y * b.Y) + (a.Z * b.Z);
	}

	inline static Vector3 Cross(const Vector3& a, const Vector3& b)
	{
		return Vector3(
			(a.Y * b.Z) - (a.Z * b.Y),
			(a.Z * b.X) - (a.X * b.Z),
			(a.X * b.Y) - (a.Y * b.X)
		);
	}

	inline static Vector3 Normalize(const Vector3& vec)
	{
		Float magnitude = vec.Length();

		return Vector3(vec.X / magnitude, vec.Y / magnitude, vec.Z / magnitude);
	}

	inline static Float Distance(const Vector3& a, const Vector3& b)
	{
		return (b - a).Length();
	}

	inline Vector3 operator+ (const Vector3& other) const
	{
		return Vector3(X + other.X, Y + other.Y, Z + other.Z);
	}

	inline Vector3 operator- (const Vector3& other) const 
	{
		return Vector3(X - other.X, Y - other.Y, Z - other.Z);
	}

	inline friend Vector3 operator* (const Float& lhs, Vector3 rhs)
	{
		return Vector3(rhs.X * lhs, rhs.Y * lhs, rhs.Z * lhs);
	}

	inline friend Vector3 operator* (const Vector3 lhs, const Float& rhs)
	{
		return Vector3(lhs.X * rhs, lhs.Y * rhs, lhs.Z * rhs);
	}

	inline friend Vector3 operator/ (const Vector3& lhs, const Float& rhs)
	{
		return Vector3(lhs.X / rhs, lhs.Y / rhs, lhs.Z / rhs);
	}

	inline friend Vector3 operator- (const Vector3& vec)
	{
		return Vector3(-vec.X, -vec.Y, -vec.Z);
	}

	inline friend std::ostream& operator<< (std::ostream& stream, const Vector3& v)
	{
		return stream << "(" << v.X << ", " << v.Y << ", " << v.Z << ")";
	}



private:


};