#pragma once
class Vector
{
public:
	double x;
	double y;
	double z;

	Vector(const double X, const double Y, const double Z) noexcept {};
	Vector(const double X, const double Y) : Vector(X, Y, 0) {};

	Vector(const double X) : Vector(X, 0, 0) {};

	Vector() : Vector(0, 0, 0) {};
	Vector(const Vector& v) noexcept {};

	Vector& operator+ (const Vector& v) const noexcept {};
	Vector& operator* (const double p) const noexcept {};
	Vector& operator- (const Vector& v) const noexcept {};
	Vector& operator/ (const double k) const noexcept {};

	double Length() const noexcept {};
	void operator+=(const Vector& other) {};
	void Rotate(const double angle) {};

};

