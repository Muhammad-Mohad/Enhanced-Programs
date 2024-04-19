#include <iostream>
using namespace std;

// sending the two parameters by reference does not make extra copies of the same variables thus saves some memory
inline int** AllocateMemory(int& rows, int& cols)
{
	cout << "Enter the number of rows: ";
	cin >> rows;

	cout << "\nEnter the number of columns: ";
	cin >> cols;

	int** matrix = new int* [rows];

	int** rowPtr = matrix;
	int** rowPtrEnd = matrix + rows;

	while (rowPtr < rowPtrEnd)
	{
		*rowPtr = new int[cols];
		rowPtr++;
	}

	return matrix;
}

// passing the rows and cols as const is important as the function cannot change the original dimensions of the matrix thus leads to save the memory leakage and prevents the memory access violation
inline void InputMatrix(int** matrix, const int& rows, const int& cols)
{
	cout << "\nEnter the numbers in the matrix: " << endl;

	int** rowPtr = matrix;
	int** rowPtrEnd = matrix + rows;

	while (rowPtr < rowPtrEnd)
	{
		int* colMax = *rowPtr;
		int* colMaxEnd = *rowPtr + cols;

		while (colMax < colMaxEnd)
		{
			cin >> *colMax;
			colMax++;
		}

		rowPtr++;
	}
}

inline void DisplayMatrix(int** matrix, const int& rows, const int& cols)
{
	cout << "\nThe matrix is:" << endl;

	int** rowPtr = matrix;
	int** rowPtrEnd = matrix + rows;

	while (rowPtr < rowPtrEnd)
	{
		int* colMax = *rowPtr;
		int* colMaxEnd = *rowPtr + cols;

		while (colMax < colMaxEnd)
		{
			cout << *colMax << "\t";
			colMax++;
		}

		cout << endl;
		rowPtr++;
	}
}

inline void DeallocateMemory(int** matrix, const int& rows)
{
	if (matrix != nullptr)
	{
		int** rowPtr = matrix;
		int** rowPtrEnd = matrix + rows;

		for (rowPtr; rowPtr < rowPtrEnd; rowPtr++)
		{
			delete[] *rowPtr;
		}

		delete[] matrix;
	}
	
}

inline int* MaxOfColumn(int** matrix, const int& rows, const int& cols)
{


	int* colMax = new int[cols];

	for (int j = 0; j < cols; j++)
	{
		int max = *((*(matrix + 0)) + j);

		for (int i = 0; i < rows; i++)
		{
			if (*((*(matrix + i)) + j) > max)
			{
				max = *((*(matrix + i)) + j);
			}
		}

		*(colMax + j) = max;
	}

	return colMax;
}

inline int* GetDiagonal(int** matrix, const int& rows, const int& cols)
{	
	if(rows != cols)
		return nullptr;

	
    int* diagonal = new int[rows];

    for(int i = 0; i < rows; i++)
    {
		*(diagonal + i) = *(*(matrix + i) + i);
    }

    return diagonal;
}

inline void DisplayDiagonal(int* matrix, const int& rows)
{
	if(matrix != nullptr)
	{
		cout << "\n\nDiagonal elements are: ";

	for(int i = 0; i < rows; i++)
		cout << *(matrix + i) << " ";
	}
	
}

inline void DisplayMatrix(int* matrix, const int& cols)
{
	cout << "\nMaximum elements of each columns are: ";

	for (int i = 0; i < cols; i++)
	{
		cout << *(matrix + i) << " ";
	}
}

inline bool IsMatrixUpperTriangular(int** matrix, const int& rows, const int& cols)
{
	for (int i = 1; i < rows; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (*((*(matrix + i)) + j) != 0)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	int rows = 0;
	int cols = 0;
	int* maxArray = nullptr;
    int* diagonal = nullptr;
	int** matrix = nullptr;
	bool check;

	matrix = AllocateMemory(rows, cols);

	InputMatrix(matrix, rows, cols);

	DisplayMatrix(matrix, rows, cols);

	maxArray = MaxOfColumn(matrix, rows, cols);

	DisplayMatrix(maxArray, cols);

	check = IsMatrixUpperTriangular(matrix, rows, cols);

	if (check)
	{
		cout << "\n\nMatrix is Upper Triangular";
	}
	else
	{
		cout << "\n\nMatrix is not Upper Triangular";
	}

    diagonal = GetDiagonal(matrix, rows, cols);

	DisplayDiagonal(diagonal, rows);

	DeallocateMemory(matrix, rows);

    delete[] maxArray;
	delete[] diagonal;

	return 0;
}