#include <iostream>
using namespace std;

class Employee
{
    protected:
        string name = "Mohad";
        int salary = 2500;
};

class Manager : public Employee
{
    public:
        void Print()
        {
            cout << name << " " << salary;
        }
};


int main()
{
    Manager m1;
    m1.Print();

    return 0;
}