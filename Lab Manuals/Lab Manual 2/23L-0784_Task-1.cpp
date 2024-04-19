#include <iostream>
using namespace std;

int* InputArray(int&);
void OutputArray(int*, const int&);
int* AllocateAndCopyArray(int*, int&, int&);
void OutputArray(int*, int, int);


int main()
{
	int size = 0;
	int* arr = nullptr;
	int size2 = 5;
	int* arr2 = nullptr;
	int currentSize = 0;
	arr2 = new int[size2];

	arr = InputArray(size);

	cout << endl;

	OutputArray(arr, size);

	cout << endl;
	cout << endl;

	arr2 = AllocateAndCopyArray(arr2, size2, currentSize);

	cout << endl;

	OutputArray(arr2, size2, currentSize);

	delete[] arr;
	delete[] arr2;
}

int* InputArray(int& size)
{
	cout << "Enter the size of the dynamically allocated aarray: ";
	cin >> size;

	int* arr = new int[size];

	cout << "Enter the elements in the first array: " << endl;
	for (int* i = arr; i < arr + size; i++)
	{
		cin >> *i;
	}

	return arr;
}

void OutputArray(int* myArray, const int& size)
{
	cout << "Output Array is: ";
	for (int* i = myArray; i < myArray + size; i++)
	{
		cout << *i << " ";
	}
}

int* AllocateAndCopyArray(int* arr, int& size, int& currentSize)
{
	int* ptr = arr;
	int* endPtr = ptr + size;
	int input;


	cout << "Enter the numbers in the second array: " << endl;
	while (true) {
		cin >> input;

		if (input == -1)
		{
			break;
		}
		if (currentSize == size)
		{
			size *= 2;
			int* newArr = new int[size];
			int* newPtr = newArr;

			for (int* i = arr; i < endPtr; i++) {
				*newPtr = *i;
				newPtr++;
			}

			delete[] arr;

			arr = newArr;
			ptr = newArr + currentSize;
		}

		currentSize++;
		*ptr = input;
		ptr++;
	}

	return arr;
}

void OutputArray(int* arr, int size, int currentSize)
{
	cout << "Array in the reverse order is: ";
	for (int* i = arr + currentSize - 1; i >= arr; i--)
	{
		cout << *i << " ";
	}
}