/*Реализуйте структуру / класс для работы с :
Для студентов с номерами кратными 3 - 3 - мерными векторами.
Для студентов чей номер по модулю 3 это 1 - Комплексными числами.
Для студентов чей номер по модулю 3 это 2 - Обыкновенными дробями.
Снабдите их всеми необходимыми для комфортной работы операторами.*/
#include <iostream>
class Ord_Frac
{
public:
	int numerator, denominator;
	double result;

	//упрощение дробей
	void simplify()
	{
		std::cout << "simplify: " << numerator << " " << denominator << std::endl;
		int i = 2;
		while ((i <= denominator) && (i <= numerator))
		{
			std::cout << "simplify loop";
			if (((denominator % i) == 0) && ((numerator % i) == 0))
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


	//проверка на ноль в знаменателе
	Ord_Frac(const int Num, const int Dem) : numerator(Num), denominator(Dem) 
	{
		if (denominator == 0)
		{
			std::cout << "fraction doesn't exist" << std::endl;
			return;
		}
		simplify();
	};

	Ord_Frac(const int Num) : numerator(Num), denominator(1) {};

	//присваивание
	void operator= (const Ord_Frac other)
	{
		numerator = other.numerator;
		denominator = other.denominator;
	};

	//сложение дробей
	Ord_Frac operator+ (const Ord_Frac other)
	{
		Ord_Frac ans = Ord_Frac(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
		return ans;
	};
	
	//дробь + число
	double operator+ (const double a)
	{
		//double ans = numerator + (a * denominator)/ denominator;
		double ans = a + numerator / double(denominator);
		return ans;
	};

	//вычитание дробей
	Ord_Frac operator- (const Ord_Frac other)
	{
		Ord_Frac ans = Ord_Frac(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
		return ans;
	};

	//домножение на число
	Ord_Frac operator* (int a)
	{
		Ord_Frac ans = Ord_Frac(numerator * a,denominator);
		return ans;
	};

	//деление на дробь
	Ord_Frac operator/ (const Ord_Frac other)
	{
		Ord_Frac ans = Ord_Frac(numerator * other.denominator, denominator * other.numerator);
		return ans;
	};

	//умножение на дробь
	Ord_Frac operator* (const Ord_Frac other)
	{
		Ord_Frac ans = Ord_Frac(numerator * other.numerator, denominator * other.denominator);
		return ans;
	};

	Ord_Frac operator- () 
	{
		Ord_Frac ans = Ord_Frac(-numerator, denominator);
		return ans;
	};
	/*
	double operator+ ()
	{
		return numerator / double(denominator);
	};
	*/
	Ord_Frac operator+ ()
	{
		Ord_Frac ans = Ord_Frac(numerator, denominator);
		return ans;
	};

	/*
	operator double() 
	{
		return numerator / double(denominator);
	};
	*/
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




/*
Vector3(const Vector3* const other) {};
*/
