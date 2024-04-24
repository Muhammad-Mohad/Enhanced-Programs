#include <iostream>
using namespace std;

class Base
{
    public:
        Base()
        {
            cout << "Base() Called\n";
        }
        ~Base()
        {
            cout << "~Base() Called\n";
        }
};

class Derived : public Base
{
    public:
        Derived()
        {
            cout << "Derived() Called\n";
        }
        ~Derived()
        {
            cout << "~Derived() Called\n";
        }
};

int main()
{
    Derived d1;

    return 0;
}