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

/*int* mergesort(int l[], int size)
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
};*/

int mai() 
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

void print_arr(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << a[i] << " ";
	};
	std::cout << std::endl;
};

int* mergesort(int a[], int size, bool(*comparator)(int, int))
{
	if (size <= 1) 
	{ 
		return a; 
	};

	int* m1 = mergesort(a, size / 2, comparator);
	int* m2 = mergesort(a + size / 2, size - (size / 2), comparator);

	int* ans = new int[size];
	//print_arr(ans, size);

	int ind1 = 0;
	int ind2 = 0;
	int f = -1;
	while (ind1 + ind2 < size)
	{
		f = -1;

		if (ind1 == size / 2)
		{
			f = 1;
		};

		if (ind2 == size - (size / 2))
		{
			f = 0;
		};

		if (f < 0 && comparator(m1[ind1], m2[ind2]))
		{
			f = 0;
		};
		if (f < 0 && comparator(m2[ind2], m1[ind1]))
		{
			f = 1;
		};

		if (f == 1)
		{
			ans[ind1 + ind2] = m2[ind2];
			ind2++;
		};
		if (f == 0)
		{
			ans[ind1 + ind2] = m1[ind1];
			ind1++;
		};
	};
	print_arr(ans, size);
	return ans;
};


bool comp_decr(int a, int b)
{
	return a > b;
};

int count_incr = 0;

bool comp_incr(int a, int b)
{
	count_incr++;
	return a < b;
};

int count = 0;

bool comp_1000(const int v1, const int v2)
{
	count++;
	if ((v1 % 1000) < (v2 % 1000))
	{
		return (v1 % 1000) < (v2 % 1000);
	}
	else
	{
		return v1 < v2;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int a[8] = { 1006, 2006, 2, 0, 1, 3, 4, 8 };
	//int b[8] = {};
	int* b = mergesort(a, 8, comp_incr);
	print_arr(a, 8);
	//std::cout << "sorted " << b[0] << std::endl;
	print_arr(b, 8);
	std::cout << "число вызовов " << count_incr << std::endl;
}



