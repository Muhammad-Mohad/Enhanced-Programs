#include <iostream>
using namespace std;

int* test()
{
	int a = 50;
	return &a;
}
int main()
{
	int* ptr = test();
	cout << *ptr;

	return 0;
}