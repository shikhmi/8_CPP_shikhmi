#include<iostream>

int main()
{
    int floors = 100;
    int count = 0;
    int i = 1;
    int sum = 0;
    while (sum <= floors) {
        sum = sum + i;
        i = i + 1;
        count = count + 1;
    }
    std::cout << count;
}

