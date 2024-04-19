#include <iostream>
using namespace std;



class Number
{
    int num1;
    int num2;

    public:
        Number(int m, int n)
        {
            num1= m;
            num2 = n;
        }

        void swap()
        {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
        void Print()
        {
            cout << "Num1: " << num1 << endl;
            cout << "Num2: " << num2 << endl;
        }
};

int main()
{
    Number m(5,10), n(5,4);

    m.Print();
    cout << endl;
    n.Print();

    m.swap();
    n.swap();   


    cout << "After swap:\n\n";
    m.Print();
    cout << endl;
    n.Print();


    return 0;
}