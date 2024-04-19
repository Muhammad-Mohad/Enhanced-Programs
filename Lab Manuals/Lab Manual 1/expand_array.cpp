#include <iostream>
using namespace std;

int main()
{
    int size = 5;
    int* arr = new int[size];
    int* ptr = arr;
    int* endPtr = arr + size;
    int currentSize = 0;
    int input = 0;

    cout << "\nInput Numbers: " << endl;
    while (true)
    {
        cin >> input;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(99, '\n');
            cout << "Invalid Input! Try Again: ";
            cin >> input;
        }

        if (input == -1)
        {
            break;
        }

        if (currentSize == size)
        {
            size *= 2;
            int *newArr = new int[size];
            int *newPtr = newArr;

            for (int* i = arr; i < endPtr; i++)
            {
                *newPtr = *i;
                newPtr++;
            }

            delete[] arr;

            arr = newArr;
            ptr = newArr + currentSize;
        }

        *ptr = input;
        ptr++;
        currentSize++;
    }

    cout << "\nNumbers in reverse order: " << endl;

    for (int* i = arr + currentSize - 1; i >= arr; i--)
    {
        cout << *i << " ";
    }

    delete[] arr;

    ptr = nullptr;
    endPtr = nullptr;

    return 0;
}