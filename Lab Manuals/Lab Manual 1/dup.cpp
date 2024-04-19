#include <iostream>
using namespace std;

int main()
{
    int size1 = 0;
    int size2 = 0;

    cout << "ENter s1: ";
    cin >> size1;

    cout << "Enetr s2: ";
    cin >> size2;

    int* arr1 = new int[size1];
    int* ptr1 = arr1;
    int* endPtr1 = arr1 + size1;

    int* arr2 = new int[size2];
    int* ptr2 = arr2;
    int* endPtr2 = arr2 + size2;


    cout << "Enter arr1: ";
    for(int* i = ptr1; i < endPtr1; i++)
        cin >> *i;

    cout << "Enter arr2: ";
    for(int* i = ptr2; i < endPtr2; i++)
        cin >> *i;

    int max = size1 + size2;
    int resultantSize = 0;
    int* newArr = new int[max];
    int* newPtr = newArr;
    int* newEndPtr = newArr + resultantSize;


    for(int* i = ptr1; i < endPtr1; i++)
        for(int* j = ptr2; j < endPtr2; j++)
        {
            if(*i == *j)
            {
                bool duplicate = false;
                for(int* k = newPtr; k < newEndPtr; k++)
                {
                    if(*i == *k)
                    {
                        duplicate = true;
                        break;
                    }
                }

                if(!duplicate)
                {
                    *newPtr = *i;
                    resultantSize++;
                    newPtr++;
                }
                break;
            }
        }


    cout << "\nIntersection:\n\n\n";
    for(int* i = newArr; i < newPtr; i++)
        cout << *i << " ";

    return 0;
}