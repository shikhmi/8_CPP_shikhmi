/*
 Размещает указатели на эти функции в массив в случайном порядке.
  Генерирует случайные аргументы для функций.
  Определяет, в каком порядке Функции попали в массив.
  Выводит в консоль порядок функций в массиве.
*/

#include <iostream>
#include <typeinfo>

#include <cstdlib>
#include <ctime>

int f1(int a, int b) {
    return a + b;
}

int f2(int a, int b) {
    return a - b;
}
int f3(int a, int b) {
    return a / b;
}
int f4(int a, int b) {
    return a % b;
}
int f5(int a, int b) {
    return a / b + a % b;
}

int main()
{
    srand(unsigned(time(0)));   // генерация случайных аргументов для функций
    int a = rand() % 100;
    int b = rand() % 100;
    std::cout << a << " " << b << std::endl; 

    setlocale(LC_ALL, "ru");

    int (*functions[5])(int, int) = { f1, f2, f3, f4, f5 };
    for (int i = 0; i <=4; i++)
    {
        functions[i](a, b);    // создаем массив из указателей на функцию
    }

    int (*randomfuncs[5])(int, int) {}; //создаём массив для рандомизации, заполняем элементами из ранее созданного массива

    for (int i = 0; i <=4;i++)
    {
    a: randomfuncs[i] = functions[rand() % 5];
        for (int j = 0; j < i; j++)
        {
            if (randomfuncs[i] == randomfuncs[j])
            {
                goto a;
            }
        }
    }

    //определение порядка
    int order[5]{};
    int i = 0;
    for (int j = 0; j <= 4; j++) { 
        while (f1(a, b) != randomfuncs[i](a, b)) //определение порядка первой функции
        {
            i += 1;
            order[j] = i;
            std::cout << order[j] << " ";
        }
        while (f2(a, b) != randomfuncs[i](a, b)) //определение порядка второй функции
        {
            i += 1;
            order[j] = i;
            std::cout << order[j] << " ";
        }
        while (f3(a, b) != randomfuncs[i](a, b)) //определение порядка третьей функции
        {
            i += 1;
            order[j] = i;
            std::cout << order[j] << " ";
        }
        while (f4(a, b) != randomfuncs[i](a, b)) //определение порядка четвёртой функции 
        {
            i += 1;
            order[j] = i;
            std::cout << order[j] << " ";
        }
        while (f5(a, b) != randomfuncs[i](a, b)) //определение порядка пятой функции
        {
            i += 1;
            order[j] = i;
            std::cout << order[j] << " ";
        }
    }
    //я понимаю, что это плохо, но пока не понимаю, почему всё так плохо, нужно чучуть больше времени

}
