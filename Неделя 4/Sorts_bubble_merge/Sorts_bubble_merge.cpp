/*
Научите функции пузырьковой и сортировки слиянием:
Сортировать значения согласно любому правилу заданному функцией типа: "bool comparator (const int& v1, const int& v2, int* const  p_counter =  nullptr)"
Продемонстрируйте возможность с помоoью такого подхода:
1)Сортировать значения в порядке возрастания
2)Сортировать значения в порядке убывания
3)Сортировать значения по : В первую очередь остатку от деления на 1000, во вторую(при равенстве остатков) по значению.
Научите компаратор по возрастанию  считать кол-во вызовов себя и оцените и сравните кол-во операций сравнения необходимых для сортировки массивов размерами 10, 100, 1000, 10000 элементов обоими алгоритмами.
*/
#include<iostream>
//#include<>

//Bubble sort
void bubblesort(int* l, int* r) {
	int size = r - l;
	int k = 0;
	if (size <= 1) { return; };

	bool unsorted = true;
	while (unsorted) {

		unsorted = false;
		for (int* i = l; i + 1 < r; i++) {
			if (*i > *(i + 1)) {
				k = (*i);
				*i = *(i + 1);
				*(i + 1) = k;
				unsorted = true;
			};
		};
		r--;
	}
}

int* mergesort(int l[], int size)
{

	//std::cout << size << std::endl;
	if (size <= 1) { return l; };

	int m = size / 2;
	int* m1 = mergesort(l, m);
	int* a = new int[size-m];

	int* m2 = mergesort(a, size-m);
	
	int ind1 = 0;
	int ind2 = 0;
	while (ind1+ind2 <= size) 
	{
		if (m1[ind1] < m2[ind2])// && (indl <= m))
		{
			l[ind1 + ind2] = m1[ind1];
			ind1++;
		}
		else 
		{
			m2[ind1 + ind2] = m2[ind2];
			ind2++;
		};
	};

	for (int i = 0; i < size; i++) 
	{
		std::cout << a[i] << " ";
	};
	std::cout << std::endl;

	return a;
};

int main() 
{
	int a[8] = {8,7,6,5,6,0,2,-1};
	
	//int* s = mergesort(a,8);
	bubblesort(&a[0], &a[8]);

	for (int i = 0; i < 8; i++) 
	{
		std::cout << a[i] << " ";
	};

	return 0;
};

