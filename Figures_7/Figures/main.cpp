#include "Vector.h"
#include <iostream>
#include "Figures.h"

int main()
{
    Vector a = Vector();
    Vector b = Vector(1.75, 2.24);
    Vector c = Vector(-1.08, 4.97);
    Triangle* t = new Triangle(a, b, c);
    t->Shift(c);
    std::cout << "shifted, now Vector b: " << t->myVertexes[1].x << " " << t->myVertexes[1].y << std::endl;
    t->StretchX(0, 2);
    std::cout << "stretchedX, now Vector b: " << t->myVertexes[1].x << " " << t->myVertexes[1].y << std::endl;

    std::cout << "perimeter: " << t->Perimeter() << std::endl;

    std::cout << "area: " << t->Area() << std::endl;

    t->Rotate(Vector(1, 1), 1);
    std::cout << "rotated, now Vector b: " << t->myVertexes[1].x << " " << t->myVertexes[1].y << std::endl;

    std::cout << (b - c).x;
    return 0;
};

