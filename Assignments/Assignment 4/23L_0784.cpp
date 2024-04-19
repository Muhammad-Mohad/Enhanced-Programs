#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{
    private:
        int real;
        int imaginary;

    public:
        ComplexNumber(int, int);
        ~ComplexNumber();
        void Input();
        void Output();
        bool IsEqual(ComplexNumber);
        ComplexNumber Conjugate();
        ComplexNumber Add(ComplexNumber);
        ComplexNumber Subtract(ComplexNumber);
        ComplexNumber Multiplication(ComplexNumber);
        float Magnitude();
};


ComplexNumber::ComplexNumber(int num1 = 0, int num2 = 0)
{
    real = num1;
    imaginary = num2;
}

ComplexNumber::~ComplexNumber()
{

}

void ComplexNumber::Input()
{
    cout << "Enter Real: ";
    cin >> real;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(99, '\n');
        cout << "Enter a valid number: ";
        cin >> real;
    }

    cout << "Enter Imaginary: ";
    cin >> imaginary;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(99, '\n');
        cout << "Enter a valid number: ";
        cin >> imaginary;
    }
}

void ComplexNumber::Output()
{
    if(imaginary >= 0)
        cout << real << "+" << imaginary << "i";

    else if(imaginary <= 0)
        cout << real  << imaginary << "i";
}

bool ComplexNumber::IsEqual(ComplexNumber c)
{
    if(real == c.real && imaginary == c.imaginary)
        return true;

    else
        return false;
}

ComplexNumber ComplexNumber::Conjugate()
{
    return ComplexNumber(real, -imaginary);
}

ComplexNumber ComplexNumber::Add(ComplexNumber c)
{
    int num1 = real + c.real;
    int num2 = imaginary + c.imaginary;

    return ComplexNumber(num1, num2);
}

ComplexNumber ComplexNumber::Subtract(ComplexNumber c)
{
    int num1 = real - c.real;
    int num2 = imaginary - c.imaginary;

    return ComplexNumber(num1, num2);
}

ComplexNumber ComplexNumber::Multiplication(ComplexNumber c)
{
    int num1 = real * c.real;
    int num2 = imaginary * c.imaginary;

    return ComplexNumber(num1, num2);
}

float ComplexNumber::Magnitude()
{
    float magnitude = sqrt(pow(real, 2) + pow(imaginary, 2));

    return magnitude;
}



int main()
{
    ComplexNumber c1, c2, conjugate_c1, conjugate_c2, add, subtract, multiply;

    cout << "\nEnter c1:\n";
    c1.Input();

    cout << "\n\nEnetr c2:\n";
    c2.Input();

    cout << "\nc1 =    "; 
    c1.Output();

    cout << "\n\nc2 =    "; 
    c2.Output();

    if(c1.IsEqual(c2) == true)
        cout << "\n\nc1 is equal to c2";
    else
        cout << "\n\nc1 is not equal to c2";

    cout << "\n\nConjugate of c1:    ";
    conjugate_c1 = c1.Conjugate();
    conjugate_c1.Output();

    cout << "\n\nConjugate of c2:    ";
    conjugate_c2 = c2.Conjugate();
    conjugate_c2.Output();

    cout << "\n\nc1 + c2:    ";
    add = c1.Add(c2);
    add.Output();

    cout << "\n\nc1 - c2:    ";
    subtract = c1.Subtract(c2);
    subtract.Output();

    cout << "\n\nc1 x c2:    ";
    multiply  = c1.Multiplication(c2);
    multiply.Output();

    float mag1 = c1.Magnitude();
    cout << "\n\nMagnitude of c1:    " << mag1;

    float mag2 = c2.Magnitude();
    cout << "\n\nMagnitude of c2:    " << mag2;

    return 0;
}
