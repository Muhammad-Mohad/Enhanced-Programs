#pragma once

#include "Point.h"

class Circle
{
private:
    Point center;
    float radius;

public:
    Circle(int, int, float);
    ~Circle();
    void Print();
};
