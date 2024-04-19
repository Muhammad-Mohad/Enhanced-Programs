#include <iostream>
#include "Triangle.h"
using namespace std;

Triangle::Triangle(int x1, int x2, int y1, int y2, int z1, int z2) : x(x1, x2), y(y1, y2), z(z1, z2)
{
	cout << "\nTriangle() Called\n";
}

Triangle::~Triangle()
{
	cout << "\n~Triangle() Called\n";
}

void Triangle::Print()
{
	cout << "\nThe coordinates of the corners of the triangle are " << "(" << x.getX() << " , " << x.getY() << "), " << "(" << y.getX() << " , " << y.getY() << ") and " << "(" << z.getX() << " , " << z.getY() << ")" << endl;
}