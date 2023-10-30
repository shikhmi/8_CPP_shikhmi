#include "Vector.h"
#include <cmath>
#include <iostream>

class Vector
{
public:
	double x;
	double y;
	double z;

	Vector(const double X, const double Y, const double Z) noexcept
	{
		x = X;
		y = Y;
		z = Z;
	};

	Vector(const double X, const double Y) : Vector(X, Y, 0) {};

	Vector(const double X) : Vector(X, 0, 0) {};

	Vector() : Vector(0, 0, 0) {};

	Vector(const Vector& v) noexcept
	{
		(*this) = v;
	};

	void operator= (const Vector& v) noexcept
	{
		x = v.x;
		y = v.y;
		z = v.z;
	};

	Vector& operator+ (const Vector& v) const noexcept
	{
		Vector ans(x + v.x, y + v.y, z + v.z);
		return ans;
	};

	Vector& operator* (const double p) const noexcept
	{
		Vector ans(x * p, y * p, z * p);
		return ans;
	};

	Vector& operator- (const Vector& v) const noexcept
	{
		Vector ans;
		ans.x = x - v.x;
		ans.y = y - v.y;
		ans.z = z - v.z;
		return ans;
	};

	Vector& operator/ (const double k) const noexcept
	{
		Vector ans(x / k, y / k, z / k);
		return ans;
	};

	double Length() const noexcept
	{
		return std::pow(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2), 0.5);
	}

	void operator+=(const Vector& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	};

	void Rotate(const double angle)
	{
		double l = Length();
		double myAngle = std::atan2(y, x);
		x = l * std::cos(myAngle + angle);
		y = l * std::sin(myAngle + angle);
		return;
	};

};