#pragma once
#include "Vector.h"
#include <vector>
#include <iostream>
class Figures
{
public:
	std::vector<Vector> myVertexes;

public:

	//����� ���� ������ �� ������ shift
	void Shift(const Vector shift) {};

	virtual double Perimeter() const {};

	virtual double Area() const {};

	// ������� ������������ ����� rotor �� (angle ������)
	void Rotate(const Vector rotor, const double angle) {};

	// ���������� ������������ ����� x = x_line � k ���
	void StretchX(const double x_line, const double k) {};

	// ���������� ������������ ����� x = x_line � k ���
	void StretchY(const double y_line, const double k) {};
};


class Triangle : public Figures
{
public:
	Triangle(Vector v1, Vector v2, Vector v3) {};

	double Area() const override {};

};
