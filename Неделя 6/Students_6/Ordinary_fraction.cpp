/*���������� ��������� / ����� ��� ������ � :
��� ��������� � �������� �������� 3 - 3 - ������� ���������.
��� ��������� ��� ����� �� ������ 3 ��� 1 - ������������ �������.
��� ��������� ��� ����� �� ������ 3 ��� 2 - ������������� �������.
�������� �� ����� ������������ ��� ���������� ������ �����������.*/
#include <iostream>


class Ord_Frac
{
public:
	int numerator, denominator;
	double result;

	//��������� ������
	void simplify()
	{
		std::cout << "simplify: " << numerator << " " << denominator << std::endl;
		int i = 1;
		while ((i <= denominator) && (i <= numerator))
		{
			std::cout << "simplify loop";
			if (((denominator % i) == 0) || ((numerator % i) == 0))
			{
				denominator = denominator / i;
				numerator = numerator / i;
			}
			else
			{
				i++;
			};
		}
		std::cout << "simplify end: " << numerator << " " << denominator << std::endl;
		return;
	};


	//�������� �� ���� � �����������
	Ord_Frac(const int Num, const int Dem) : numerator(Num), denominator(Dem) 
	{
		if (denominator == 0)
		{
			std::cout << "fraction doesn't exist" << std::endl;
			return;
		}
		simplify();
	};

	//������������
	void operator= (const Ord_Frac other)
	{
		numerator = other.numerator;
		denominator = other.denominator;
	};

	//�������� ������
	Ord_Frac operator+ (const Ord_Frac other)
	{
		Ord_Frac ans = Ord_Frac(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
		return ans;
	};

	//��������� ������
	Ord_Frac operator- (const Ord_Frac other)
	{
		Ord_Frac ans = Ord_Frac(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
		return ans;
	};

	//���������� �� �����
	Ord_Frac operator* (const double a)
	{
		Ord_Frac ans = Ord_Frac(numerator * a, denominator);
		return ans;
	};

	//������� �� �����
	Ord_Frac operator/ (const Ord_Frac other)
	{
		Ord_Frac ans = Ord_Frac(numerator * other.denominator, denominator * other.numerator);
		return ans;
	};

	//��������� �� �����
	Ord_Frac operator* (const Ord_Frac other)
	{
		Ord_Frac ans = Ord_Frac(numerator * other.numerator, denominator * other.denominator);
		return ans;
	};

};
/*class Vector3
{
public:
	double x, y, z;

	Vector3(const double X, const double Y, const double Z) : x(X), y(Y), z(Z){};

	Vector3(const double X, const double Y) : Vector3(X,Y,0) {};

	Vector3(const double X) : Vector3(X, 0, 0) {};

	Vector3() : Vector3(0, 0, 0) {};

	Vector3 operator+ (const Vector3 other) const
	{
		Vector3 ans = Vector3(x + other.x, y + other.y, z + other.z);
		return ans;
	};

	void operator= (const Vector3 other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	};
};*/
