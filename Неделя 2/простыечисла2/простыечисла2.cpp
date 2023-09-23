// простыечисла2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

int* IncreaseArray(int* arr,int n)
{
    int* newarr = new int[n+1];

    for (int i = 0; i < n; i++)
    {
        newarr[i] = arr[i];
    };
    newarr[n] = 0;
    return newarr;
};

int* primarynumbers(int upbound)
{
    int* prnums = new int[1];
    int size = 1;
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
        while (i < size && prnums[i] < std::pow(upbound, 0.5) && isprimary)
        {

            if (inumber % prnums[i] == 0)
            {
                isprimary = false;
            };

            i++;
        };

        if (isprimary)
        {
            prnums = IncreaseArray(prnums, size);
            prnums[size] = inumber;
            size++;
        };
    };

    for (int i = 1; i < size; i++)
    {
        std::cout << prnums[i] << " ";
    };
    std::cout << std::endl;

    return prnums;
};

int main()
{
    int n;
    std::cin >> n;

    primarynumbers(n);



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