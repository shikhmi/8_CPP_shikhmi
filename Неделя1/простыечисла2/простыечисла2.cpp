// простыечисла2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <cmath>
std::vector<int> PrimaryNumbers(int UpperBound)
{
    std::vector<int> primaryNumbers = {};
    for (int iNumber = 2; iNumber < UpperBound; iNumber++)
    {
        bool IsPrimary = true;
        /*
        for (int i = 0; i < primaryNumbers.size(); i++) 
        {

            if (iNumber % primaryNumbers[i] == 0)
            {
                IsPrimary = false;
            };

        };
        */
        int i = 0;
        while (i < primaryNumbers.size() && primaryNumbers[i] < std::pow(UpperBound, 0.5) && IsPrimary)
        {

            if (iNumber % primaryNumbers[i] == 0)
            {
                IsPrimary = false;
            };

            i++;
        };

        if (IsPrimary) 
        {
            primaryNumbers.push_back(iNumber);
        };
    };

    return primaryNumbers;
};

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> prime = PrimaryNumbers(n);

    for (int j = 0; j < prime.size(); j++)
    {
        std::cout << prime[j] << " ";
    };

    return 0;
};

/*
void sn(int* arr, int n)
{
    int n = 0;
    std::cout << "Введите число";
    std::cin >> n;
    if (n == 1) {
        std::cout << "Меньших простых чисел нет";
    }
    int size = 1; //размер массива
    for (int i = 2; i < n; i++) {
        int j = 2;
        for (j; j < i; j++) {
            if (i % j == 0){
                break;
            }
            if (i % j != 0){
                arr[size] = i;
                ++size;
                push_back(arr, size, i);
            }
        }
    }
    std::cout << arr[size];
}

void push_back(int*& arr, int &size, const int value)
{
    int *newarr = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        newarr[i] = arr[i];
    }
    newarr[size++] = value;
    delete[] arr;
    arr = newarr;
}
// ва открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
*/