#include <iostream>
#include "Circle.h"
using namespace std;

Circle::Circle(int num1, int num2, float rad) : center(num1, num2)
{
    radius = rad;

    cout << "\nCircle() Called\n";
}

Circle::~Circle()
{
    cout << "\n~Circle() Called\n";
}

void Circle::Print()
{
    cout << "\nThe centre of the circle is " << "(" << center.getX() << " , " << center.getY() << ")" << " and radius is " << radius << endl;
}