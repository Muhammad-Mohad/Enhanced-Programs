#pragma once

class Point
{
private:
    int x;
    int y;

public:
    Point(int, int);
    void Print();
    ~Point();
    int getX();
    int getY();
};
