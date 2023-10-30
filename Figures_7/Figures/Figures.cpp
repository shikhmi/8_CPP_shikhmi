#include "Figures.h"
#include <vector>
#include <iostream>

class Figure
{
public:
	std::vector<Vector> myVertexes;

public:

	//сдвиг всей фигуры на вектор shift
	void Shift(const Vector shift)
	{
		for (int i = 0; i < myVertexes.size(); i++)
		{
			myVertexes[i] += shift;
		};
	};

	virtual double Perimeter() const
	{
		double p = 0;
		for (int i = 1; i < myVertexes.size(); i++)
		{
			p += (myVertexes[i] - myVertexes[i - 1]).Length();
		};
		p += (myVertexes[myVertexes.size() - 1] - myVertexes[0]).Length();
		return p;
	};

	virtual double Area() const
	{
		double c = 0.0;
		return 0 / c;
	};

	// поворот относительно точки rotor на (angle радиан)
	void Rotate(const Vector rotor, const double angle)
	{
		for (int i = 0; i < myVertexes.size(); i++)
		{
			Vector f = myVertexes[i];
			Vector s;
			s.x = f.x - rotor.x; s.y = f.y - rotor.y; s.z = f.z - rotor.z;
			s.Rotate(angle);

			myVertexes[i] = rotor + s;
		};

		return;
	};

	// растяжение относительно линии x = x_line в k раз
	void StretchX(const double x_line, const double k)
	{
		for (int i = 0; i < myVertexes.size(); i++)
		{
			myVertexes[i].x = (myVertexes[i].x - x_line) * k + x_line;
		};
	};

	// растяжение относительно линии x = x_line в k раз
	void StretchY(const double y_line, const double k)
	{
		for (int i = 0; i < myVertexes.size(); i++)
		{
			myVertexes[i].y = (myVertexes[i].y - y_line) * k + y_line;
		};
	};
};

class Triangle : public Figure
{
public:
	Triangle(Vector v1, Vector v2, Vector v3)
	{
		myVertexes.reserve(3);
		myVertexes.push_back(v1);
		myVertexes.push_back(v2);
		myVertexes.push_back(v3);
	};

	double Area() const override
	{
		double l1 = (myVertexes[1] - myVertexes[0]).Length();
		double l2 = (myVertexes[2] - myVertexes[1]).Length();
		double l3 = (myVertexes[0] - myVertexes[2]).Length();

		double p = (l1 + l2 + l3) / 2.0;
		return std::pow((p * (p - l1) * (p - l2) * (p - l3)), 0.5);
	};
};