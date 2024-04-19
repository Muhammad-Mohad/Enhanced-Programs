#pragma once

#include "Point.h"

class Triangle
{
	private:
		Point x;
		Point y;
		Point z;

	public:
		Triangle(int, int, int, int, int, int);
		~Triangle();
		void Print();
};