#include <iostream>
#include <fstream>
using namespace std;

int** InputMatrix(ifstream&, int&, int&);                                           // reads the values of dimensions and data of matrices
void OutputMatrix(int**, const int&, const int&);                                   // displays the matrix
int** AddMatrix(int**, int**, const int&, const int&);                              // performs addition on two matrices of same dimensions
int** TransposeMatrix(int**, const int&, const int&);                               // takes tranpose of a matrix
bool IsSymmetric(int**, const int&, const int&);                                    // checks whether a matrix is symmetric or not
void InterChangeRows(int**, const int&, const int&);                                // takes the base address of the matrix and calls another function to swap rows
void InterChangeRows(int*&, int*&);                                                 // swaps the rows of a matrix
void DeallocatingMatrix(int**, const int&);                                         // deletes the dynamically allocated matrices
bool IsAdditionPossible(const int&, const int&, const int&, const int&);            // checks two matrices if they are compatible for addition or not

int main()
{
    int** matrixA = nullptr;
    int** matrixB = nullptr;
    int** matrixC = nullptr;
    int** matrixSumAB = nullptr;
    int** matrixSumAC = nullptr;
    int** transposeA = nullptr;
    int** transposeB = nullptr;
    int** transposeC = nullptr;

    int rowsA = 0;
    int colsA = 0;
    int rowsB = 0;
    int colsB = 0;
    int rowsC = 0;
    int colsC = 0;
    
    bool checkForAddition;
    bool checkForSymmetric;

    ifstream inputFile("InputFile.txt");    // opening the file

    if (inputFile.is_open())
    {
        matrixA = InputMatrix(inputFile, rowsA, colsA);    // retrieving the data of first matrix and displaying it
        cout << "Matrix A =" << endl;
        OutputMatrix(matrixA, rowsA, colsA);

        cout << endl;

        matrixB = InputMatrix(inputFile, rowsB, colsB);    // retrieving the data for second matrix and displaying it
        cout << "Matrix B =" << endl;
        OutputMatrix(matrixB, rowsB, colsB);

        cout << endl;

        matrixC = InputMatrix(inputFile, rowsC, colsC);    // retrieving the data for second matrix and displaying it
        cout << "Matrix C =" << endl;
        OutputMatrix(matrixC, rowsC, colsC);

        cout << endl;

        cout << "A + B =" << endl;                         // adding two matrices after checking if addition is valid and displaying it
        checkForAddition = IsAdditionPossible(rowsA, colsA, rowsB, colsB);
        if (checkForAddition)
        {
            matrixSumAB = AddMatrix(matrixA, matrixB, rowsA, colsA);
            OutputMatrix(matrixSumAB, rowsA, colsA);
        }
        else
        {
            cout << "Addition not possible.";
        }

        cout << endl;

        cout << "A + C =" << endl;                          // adding two matrices after checking if addition is valid and displaying it
        checkForAddition = IsAdditionPossible(rowsA, colsA, rowsC, colsC);
        if (checkForAddition)
        {
            matrixSumAC = AddMatrix(matrixA, matrixC, rowsA, colsA);
            OutputMatrix(matrixSumAC, rowsA, colsA);
        }
        else
        {
            cout << "Addition not possible." << endl;
        }

        cout << endl;

        transposeA = TransposeMatrix(matrixA, rowsA, colsA);    // taking tranpose of first matrix and displaying it
        cout << "Transpose of A =" << endl;
        OutputMatrix(transposeA, colsA, rowsA);

        cout << endl;

        transposeB = TransposeMatrix(matrixB, rowsB, colsB);    // taking tranpose of second matrix and displaying it
        cout << "Transpose of B =" << endl;
        OutputMatrix(transposeB, colsB, rowsB);

        cout << endl;

        transposeC = TransposeMatrix(matrixC, rowsC, colsC);    // taking tranpose of third matrix and displaying it
        cout << "Transpose of C =" << endl;
        OutputMatrix(transposeC, colsC, rowsC);

        cout << endl;

        checkForSymmetric = IsSymmetric(matrixA, rowsA, colsA);     // checking if first matrix is symmetric or not
        if (checkForSymmetric)
        {
            cout << "Matrix A is Symmetric" << endl;
        }
        else {
            cout << "Matrix A is Not Symmetric" << endl;
        }

        cout << endl;

        checkForSymmetric = IsSymmetric(matrixB, rowsB, colsB);     // checking if second matrix is symmetric or not
        if (checkForSymmetric)
        {
            cout << "Matrix B is Symmetric" << endl;
        }
        else {
            cout << "Matrix B is Not Symmetric" << endl;
        }

        cout << endl;

        checkForSymmetric = IsSymmetric(matrixC, rowsC, colsC);     // checking if third matrix is symmetric or not
        if (checkForSymmetric)
        {
            cout << "Matrix C is Symmetric" << endl;
        }
        else {
            cout << "Matrix C is Not Symmetric" << endl;
        }

        cout << endl;

        InterChangeRows(matrixA, rowsA, colsA);     // interchanging rows of first matrix


        // Dealloacting the dynamically created matrices 
        DeallocatingMatrix(matrixA, rowsA);
        DeallocatingMatrix(matrixB, rowsB);
        DeallocatingMatrix(matrixC, rowsC);
        DeallocatingMatrix(matrixSumAB, rowsA);
        DeallocatingMatrix(matrixSumAC, rowsA);
        DeallocatingMatrix(transposeA, colsA);
        DeallocatingMatrix(transposeB, colsB);
        DeallocatingMatrix(transposeC, colsC);

        // closing the file after working with it
        inputFile.close();
    }
    else
    {
        cout << "Error opening the file";
    }
}



int** InputMatrix(ifstream& inputFile, int& rows, int& cols)
{
    inputFile >> rows >> cols;

    if (rows <= 0 || cols <= 0)
    {
        cout << "Invalid dimensions for matrix.";
        exit(EXIT_FAILURE);
    }
    

    int** matrix = new int* [rows];

    int** rowPtr = matrix;
    int** rowEnd = matrix + rows;

    while (rowPtr < rowEnd)
    {
        *rowPtr = new int[cols];
        rowPtr++;
    }

    rowPtr = matrix;

    while (rowPtr < rowEnd)
    {
        int* colPtr = *rowPtr;
        int* colEnd = *rowPtr + cols;

        while (colPtr < colEnd)
        {
            inputFile >> *colPtr;
            colPtr++;
        }
        rowPtr++;
    }

    return matrix;
}

void OutputMatrix(int** matrix, const int& ROWS, const int& COLS)
{
    int** iPtr = matrix;
    int** iEndPtr = matrix + ROWS;


    for (iPtr; iPtr < iEndPtr; iPtr++)
    {
        int* jPtr = *iPtr;
        int* jEndPtr = *iPtr + COLS;

        for (jPtr; jPtr < jEndPtr; jPtr++)
        {
            cout << *jPtr << "\t";
        }
        cout << endl;
    }
}

int** AddMatrix(int** matrixA, int** matrixB, const int& ROWS, const int& COLS)
{
    int** result = new int* [ROWS];

    int** rowPtr = result;
    int** rowPtrEnd = result + ROWS;

    int** rowPtrA = matrixA;
    int** rowPtrB = matrixB;

    while (rowPtr < rowPtrEnd)
    {
        *rowPtr = new int[COLS];
        int* colPtr = *rowPtr;

        int* colPtrA = *rowPtrA;
        int* colPtrB = *rowPtrB;

        int* colPtrEnd = colPtr + COLS;

        while (colPtr < colPtrEnd)
        {
            *colPtr = *colPtrA + *colPtrB;
            colPtr++;
            colPtrA++;
            colPtrB++;
        }

        rowPtr++;
        rowPtrA++;
        rowPtrB++;
    }

    return result;
}

int** TransposeMatrix(int** matrix, const int& ROWS, const int& COLS)
{
    int** transpose = new int* [COLS];

    for (int i = 0; i < COLS; i++)
    {
        *(transpose + i) = new int[ROWS];
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            *((*(transpose + j)) + i) = *((*(matrix + i)) + j);
        }
    }

    return transpose;
}


bool IsSymmetric(int** matrix, const int& ROWS, const int& COLS)
{
    int** transpose = TransposeMatrix(matrix, ROWS, COLS);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (*(*(matrix + i) + j) != *(*(transpose + i) + j))
            {
                DeallocatingMatrix(transpose, COLS);
                return false;
            }
        }
    }

    DeallocatingMatrix(transpose, COLS);
    return true;
}

void InterChangeRows(int** matrix, const int& ROWS, const int& COLS)
{
    int row1 = 1;
    int row2 = 3;
    cout << "Interchanging Rows of Matrix A:\n";
    cout << "row1: " << row1 << endl;
    cout << "row2: " << row2 << endl;

    InterChangeRows(*((matrix-1)+row1), *((matrix-1) + row2));

    cout << "\nAfter Interchanging Rows Matrix A =" << endl;
    OutputMatrix(matrix, ROWS, COLS);
}

void InterChangeRows(int*& row1, int*& row2)
{
    int* tempRow = row1;
    row1 = row2;
    row2 = tempRow;
}

void DeallocatingMatrix(int** matrix, const int& rows)
{
    if (matrix != nullptr)
    {
        int** rowPtr = matrix;
        int** rowEnd = matrix + rows;

        while (rowPtr < rowEnd)
        {
            delete[] *rowPtr;
            rowPtr++;
        }

        delete[] matrix;
    }
}

bool IsAdditionPossible(const int& rowsA, const int& colsA, const int& rowsB, const int& colsB)
{
    if ((rowsA == rowsB) && (colsA == colsB))
    {
        return true;
    }
    else
    {
        return false;
    }
}


