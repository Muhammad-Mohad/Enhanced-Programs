#include <iostream>
#include "ComplexNumber.h"
using namespace std;

int main()
{
    ComplexNumber c1;


    c1.Input();

    cout << "\nc1 is : ";
    c1.Output();


    ComplexNumber* cPtr = new ComplexNumber(3, 5);

    cout << "\ncPtr is : ";
    cPtr->Output();

    delete cPtr;

    ComplexNumber arr[5];

    cout << "\nArray on Stack:\n\n";

    for(int i = 0; i < 5; i++)
    {
        cout << "\nEnter values for arr[" << i << "] :\n";
        arr[i].Input();
    }

    for(int i = 0; i < 5; i++)
    { 
        cout << "\narr[" << i << "] is : ";
        arr[i].Output();

        cout << "Magnitude of arr[" << i << "] is : " << arr[i].Magnitude() << endl;
    }

    int size = 0;

    cout << "\nEnter the size of the dynamically allocated array of complex numbers : ";
    cin >> size;

    ComplexNumber* ptr = new ComplexNumber[size];

    for(int i = 0; i < size; i++)
    {
        cout << "\nEnter values for ptr[" << i << "] :\n";
        ptr[i].Input();
    }

    for(int i = 0; i < size; i++)
    {
        cout << "\nptr[" << i << "] is : ";
        ptr[i].Output();

        cout << "Magnitude of ptr[" << i << "] is : " << ptr[i].Magnitude() << endl;
    }

    delete[] ptr;



    // ComplexNumber c1(56, -3), c2(8, -6);

    // ComplexNumber sum = c1.Add(c2);
    // sum.Output();





    // ComplexNumber c1(3,4);
    // ComplexNumber c2(4,5);

    // {
    // ComplexNumber temp = c1;
    // c1 = c2;
    // c2 = temp;
    // }
    
    // c1.Output();
    // c2.Output();




    // ComplexNumber c1(5,10);

    // {
    // ComplexNumber c2(c1);
    // cout << "c2 = ";
    // c2.Output();
    // }

    // cout << "c1 = ";
    // c1.Output();




    // ComplexNumber c1(3, 4);

    // {
    //     ComplexNumber c2, c3;
    //     c3 = c2  = c1;

    //     c2.Output();
    //     c3.Output();
    // }

    // c1.Output();

}