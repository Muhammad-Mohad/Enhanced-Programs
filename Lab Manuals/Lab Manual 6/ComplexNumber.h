#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{
    private:
        int* real;
        int* imaginary;

    public:
        ComplexNumber(int, int);
        ~ComplexNumber();
        void Input();
        void Output();
        float Magnitude();

        ComplexNumber(const ComplexNumber&);
        ComplexNumber& operator=(const ComplexNumber&);
        
        ComplexNumber Add(ComplexNumber);
};

ComplexNumber::ComplexNumber(int num1 = 0, int num2 = 0)
{
    cout << "\nConstructor Called\n\n";

    real = new int;
    imaginary = new int;

    *real = num1;
    *imaginary = num2;
}

ComplexNumber::~ComplexNumber()
{
    cout << "\nDesctructor Called\n";

    delete real;
    delete imaginary;
}

void ComplexNumber::Input()
{
    cout << "Enter the real number : ";
    cin >> *real;

    cout << "Enter the imaginary number : ";
    cin >> *imaginary;
}

void ComplexNumber::Output()
{
    if(*imaginary >= 0)
        cout << *real << "+" << *imaginary << "i" << endl;

    else
        cout << *real << *imaginary << "i" << endl;
}

float ComplexNumber::Magnitude()
{
    float mag = sqrt(pow(*real, 2) + pow(*imaginary, 2));
    return mag;
}

ComplexNumber::ComplexNumber(const ComplexNumber& c)
{
    cout << "\nCopy Constructor Called\n";
    
    real = new int(*c.real);
    imaginary = new int(*c.imaginary);
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& c)
{
    *real = *c.real;
    *imaginary = *c.imaginary;
     
    return *this;
}

ComplexNumber ComplexNumber::Add(ComplexNumber c)
{
    int num1 = *real + *c.real;
    int num2 = *imaginary + *c.imaginary;

    return ComplexNumber(num1, num2);
}