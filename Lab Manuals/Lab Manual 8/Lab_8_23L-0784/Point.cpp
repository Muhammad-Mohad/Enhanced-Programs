#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(int num1, int num2)
{
    x = num1;
    y = num2;

    cout << "\nPoint() Called\n";
}

void Point::Print()
{
    cout << "(" << x << " , " << y << ")\n";
}

Point::~Point()
{
    cout << "\n~Point() Called\n";
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}