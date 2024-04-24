#include <iostream>
using namespace std;

class Shape
{
    public:
        virtual float calculateArea()
        {
            return 0.0;
        }
};

class Rectangle : public Shape
{
    private:
        float length = 4.5;
        float width = 2.25;

    public:
        float calculateArea()
        {
            return length * width;
        }
};

class Circle : public Shape
{
    private:
        float radius = 5.1;

    public:
        float calculateArea()
        {
            return 3.14 * radius * radius;
        }
};

class Triangle : public Shape
{
    private:
        float length = 5.5;
        float width = 1.2;

    public:
        float calculateArea()
        {
            return 0.5 * length * width;
        }
};

int main()
{
    Shape* shape[3];
    Triangle t1;
    Circle c1;
    Rectangle r1;

    shape[0] = &c1;
    shape[1] = &r1;
    shape[2] = &t1;

    for(int i = 0; i < 3; i++)
    {
        cout << shape[i]->calculateArea() << endl;
    }

    return 0;
}