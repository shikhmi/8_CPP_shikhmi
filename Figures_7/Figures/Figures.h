#pragma once
#include "Vector.h"
#include <vector>
#include <iostream>
class Figures
{
public:
	std::vector<Vector> myVertexes;

public:

	//сдвиг всей фигуры на вектор shift
	void Shift(const Vector shift) {};

	virtual double Perimeter() const {};

	virtual double Area() const {};

	// поворот относительно точки rotor на (angle радиан)
	void Rotate(const Vector rotor, const double angle) {};

	// растяжение относительно линии x = x_line в k раз
	void StretchX(const double x_line, const double k) {};

	// растяжение относительно линии x = x_line в k раз
	void StretchY(const double y_line, const double k) {};
};


class Triangle : public Figures
{
public:
	Triangle(Vector v1, Vector v2, Vector v3) {};

	double Area() const override {};

};
