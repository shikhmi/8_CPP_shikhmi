// Class_OCD.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// 
/*
Пугающие образы и влечения;
Компульсивные поступки (ритуалы);
Навязчивая проверка собственных действий;
Страх неприятностей, загрязнения или заражения;
Необъяснимое стремление что-либо считать;
Чрезмерная организованность и педантичность;
Перфекционизм в отношениях, работе и даже в отдыхе;
«Застревание», «зацикливание» на своих мыслях.
*/
//#include "Drugs.cpp"
#include <iostream>
#include <string>
#include "Diseases.h"

/*class Diseases
{
private:
    int depression;
    int ocd;
    int panic_attacks;
    int anorexia;

public:
    Diseases(int d, int o, int p, int a);
    int frightening_drives();
    int excessive_pedantry();
    int apathy();
    int overeating();
    int obsessive_thoughts();
};*/


int main() 
{
    Diseases::OCD* myOCD = new Diseases::OCD();
    std::cout << myOCD->storytelling();
    return 0;
};


/*class A
{
private:
    int a;
protected:
    int g;
public:
    int h;

    virtual void function()
    {
        return;
    }

    void foo() {};
};

class B : public A 
{
public:
    void s() 
    {
        g = 0;
    };

    void function() override
    {
        h = 1;
    };

    void func() {};

    B* operator= (const B* other) 
    {

    };

    void operator<< (std::ostream out)
    {
        out << g << " " << std::endl;
        return;
    };

    //void operator-> () {};
};

int f()
{
    A* a = new A();
    a->function();
    B* b = new B();
    b->function();
    std::cout << a;

    Disease* d = new Disease(1,1,1,2,1);
};


class Human 
{
};

class BattleHelicopter : public Human {};

class Student : public Human {};

class Group 
{
public:
    Human* myChildren[];
};*/