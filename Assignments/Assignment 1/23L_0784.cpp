#include <iostream>
#include <fstream>
using namespace std;

int* ReadInputFromFile(int*, int&, ifstream&, int);    // reads array elements, array size from input file
void DisplayArrayContent(int*, const int);             // takes base address and size of array and displays it
void SortingContentOfArray(int*, const int);           // sorts the content of array
void DistinctElementsOfArray(int*, int&);              // makes an array unique
int* UnionOfArrays(int*, int, int*, int, int&);        // combines and sorts the array
void DisplayArray(int*, int*);                         // takes base address and last address of array elements and displays it

int main()
{
    int size1 = 0;
    int size2 = 0;
    int unionSize = 0;
    int* arr1 = nullptr;
    int* arr2 = nullptr;
    int* unionArr = nullptr;

    ifstream inputFile("Data1.txt");     // Opening the file to read data

    if (inputFile.is_open())       
    {
        arr1 = ReadInputFromFile(arr1, size1, inputFile, 1);
        cout << endl << endl;

        arr2 = ReadInputFromFile(arr2, size2, inputFile, 2);
        cout << endl << endl;

        cout << "Union of Array 1 and Array 2:" << endl;

        // sorted union array
        unionArr = UnionOfArrays(arr1, size1, arr2, size2, unionSize);
        DistinctElementsOfArray(unionArr, unionSize);    // displaying distinct elements of union array


        // allocated memory freed up
        delete[] arr1;
        delete[] arr2;
        delete[] unionArr;

        inputFile.close();    // closing the file
    }
    else
    {
        cout << "Error opening the file";    // if file is corrupted or not found, give an error
    }

    return 0;
}




int* ReadInputFromFile(int* array, int& size, ifstream& inputFile, int arrayNumber)
{
    inputFile >> size;
    if (size <= 0)
    {
        cout << "Enter a valid size for the array " << arrayNumber;    
        exit(EXIT_FAILURE);   // if array size is 0 or less, program terminates displaying an error message
    }

    int* arr = new int[size];
    int* ptr = arr;
    int* endPtr = ptr + size;

    for (ptr; ptr < endPtr; ptr++)
    {
        inputFile >> *ptr;
    }

    // displaying array content
    cout << "Input Array " << arrayNumber << ":" << endl;
    DisplayArrayContent(arr, size);

    // displaying the sorted array
    cout << "\n\nSorted Array " << arrayNumber << ":" << endl;
    SortingContentOfArray(arr, size);

    // displaying the unique array
    cout << "\n\nDistinct Elements in Array " << arrayNumber << ":" << endl;
    DistinctElementsOfArray(arr, size);

    return arr;    // returning the base address of array
}



void DisplayArrayContent(int* array, const int arraySize)
{
    int* ptr = array;
    int* endPtr = ptr + arraySize;

    DisplayArray(ptr, endPtr);
}



void SortingContentOfArray(int* array, const int arraySize)
{
    int* ptr = array;
    int* endPtr = array + arraySize;
    int temp = 0;

    // Selection Sort
    for (int* i = ptr; i < endPtr; i++)
    {
        for (int* j = i; j < endPtr; j++)
        {
            if (*i > *j)
            {
                temp = *j;
                *j = *i;
                *i = temp;
            }
        }
    }

    DisplayArray(ptr, endPtr);
}



void DistinctElementsOfArray(int* array, int& arraySize)
{
    int newSize = 1;
    int* endPtr = array + arraySize;

    // only choosing the distinct elements
    for (int* ptr = array + 1; ptr < endPtr; ptr++)
    {
        if (*ptr != *(ptr - 1))
        {
            *(array + newSize) = *ptr;
            newSize++;
        }
    }

    DisplayArray(array, array + newSize);
}



int* UnionOfArrays(int* array1, int size1, int* array2, int size2, int& unionSize)
{
    int maxSize = size1 + size2;
    int* resultantArray = new int[maxSize];

    int* resultPtr = resultantArray;
    int* ptr1 = array1;
    int* endPtr1 = ptr1 + size1;

    // Combining the array
    for (ptr1; ptr1 < endPtr1; ptr1++)
    {
        *resultPtr = *ptr1;
        resultPtr++;
    }

    int* ptr2 = array2;
    int* endPtr2 = ptr2 + size2;

    for (ptr2; ptr2 < endPtr2; ptr2++)
    {
        *resultPtr = *ptr2;
        resultPtr++;
    }

    unionSize = maxSize;

    // Selection Sort on the combined array
    int temp = 0;
    
    for (int* i = resultantArray; i < resultPtr; i++)
    {
        for (int* j = i; j < resultPtr; j++)
        {
            if (*i > *j)
            {
                temp = *j;
                *j = *i;
                *i = temp;
            }
        }
    }

    return resultantArray;      // returning the base address of the combined array
}



void DisplayArray(int* ptr, int* endPtr)
{
    for (ptr; ptr < endPtr; ptr++)
    {
        cout << *ptr;
        if(ptr != endPtr - 1)
        {
            cout << ", ";
        }
    }
}
