// простыечисла2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>
std::vector<int> primarynumbers(int upbound)
{
    std::vector<int> prnums = {};
    for (int inumber = 2; inumber < upbound; inumber++)
    {
        bool isprimary = true;
        /* это штука без квадрата
        for (int i = 0; i < primaryNumbers.size(); i++)
        {

            if (iNumber % primaryNumbers[i] == 0)
            {
                IsPrimary = false;
            };

        };
        */
        int i = 0;
        while (i < prnums.size() && prnums[i] < std::pow(upbound, 0.5) && isprimary)
        {

            if (inumber % prnums[i] == 0)
            {
                isprimary = false;
            };

            i++;
        };

        if (isprimary)
        {
            prnums.push_back(inumber);
        };
    };

    return prnums;
};

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> prime = primarynumbers(n);

    for (int j = 0; j < prime.size(); j++)
    {
        std::cout << prime[j] << " ";
    };

    return 0;
};

/* это моя неудачная попытка, сюда лучше не смотреть*/
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
*/