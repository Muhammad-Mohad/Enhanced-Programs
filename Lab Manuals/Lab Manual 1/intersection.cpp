#include <iostream>
using namespace std;

int main()
{
    int size1 = 0;
    int size2 = 0;

    cout << "\nEnter the size of first array: ";
    cin >> size1;
    // while (cin.fail())
    // {
    //     cin.clear();
    //     cin.ignore(99, '\n');
    //     cout << "Invalid Input! Try Again: ";
    //     cin >> size1;
    // }

    int* arr1 = new int[size1];
    int* ptr1 = arr1;
    int* endPtr1 = arr1 + size1;

    cout << "\nInput the numbers in first array: " << endl;

    for (int* i = ptr1; i < endPtr1; i++)
    {
        cin >> *i;
        // while (cin.fail())
        // {
        //     cin.clear();
        //     cin.ignore(99, '\n');
        //     cout << "Invalid Input! Try Again: ";
        //     cin >> *i;
        // }
    }

    cout << "\nEnter the size of second array: ";
    cin >> size2;
    // while (cin.fail())
    // {
    //     cin.clear();
    //     cin.ignore(99, '\n');
    //     cout << "Invalid Input! Try Again: ";
    //     cin >> size2;
    // }

    int* arr2 = new int[size2];
    int* ptr2 = arr2;
    int* endPtr2 = arr2 + size2;

    cout << "\nInput the numbers in second array: " << endl;

    for (int* i = ptr2; i < endPtr2; i++)
    {
        cin >> *i;
        // while (cin.fail())
        // {
        //     cin.clear();
        //     cin.ignore(99, '\n');
        //     cout << "Invalid Input! Try Again: ";
        //     cin >> *i;
        // }
    }

    int resultantSize = 0;
    int maxSize = size1 + size2;
    int* resultantArr = new int[maxSize];
    int* resultantPtr = resultantArr;
    int* resultantEndPtr = resultantPtr + resultantSize;

    for (int* i = ptr1; i < endPtr1; i++)
    {
        for (int* j = ptr2; j < endPtr2; j++)
        {
            if (*i == *j)
            {
                bool duplicate = false;
                for (int* k = resultantPtr; k < resultantEndPtr; k++)
                {
                    if (*k == *i)
                    {
                        duplicate = true;
                        break;
                    }
                }

                if (!duplicate)
                {
                    *resultantPtr = *i;
                    resultantPtr++;
                    resultantSize++;
                }
                break;
            }
        }
    }

    cout << "\nIntersection of two arrays is: ";
    for (int* i = resultantArr; i < resultantPtr; i++)
    {
        cout << *i << " ";
    }

    delete[] arr1;
    delete[] arr2;
    delete[] resultantArr;

    ptr1 = nullptr;
    endPtr1 = nullptr;
    ptr2 = nullptr;
    endPtr2 = nullptr;
    resultantPtr = nullptr;

    return 0;
}