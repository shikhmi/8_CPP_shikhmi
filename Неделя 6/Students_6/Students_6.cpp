﻿// Students_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Ordinary_fraction.cpp"

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
		//Ord_Frac fhh = Ord_Frac(1, 0);
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
