#include <iostream>
#include "Class_OrdFrac.cpp"

int main()
{
	double numb = 2;
	int num = 3;
	try
	{
		Ord_Frac a = Ord_Frac(1, 2);
		Ord_Frac b = Ord_Frac(2, 2);
		Ord_Frac c = a + b;
		double j = a + numb;
		Ord_Frac x = a + num;
		Ord_Frac fhh = Ord_Frac(1, 0);
		std::cout << std::endl << c.numerator << " " << c.denominator;
		std::cout << std::endl << j;
	}
	catch (std::exception* except)
	{
		std::cout << except->what() << std::endl;
		exit(-1);
	};
	//Ord_Frac bgj = + b;

	//double x = a + num;

	return 0;
};