#include <iostream>
using namespace std;


class A {
char c1, c2;
public:
A()
{ c1 = 'z';
cout << c2 << ",";
}
A(char c)
{ c2 = 'A';
cout << c << ",";
}
void setC1(char n1) { c1 = n1; }
void setC2(char n2) { c2 = n2; }
void swap() { c1 = c2; c2 = c1; }
char getC1() { return c1; }
char getC2() { return c2; }
};

int main() {
A a1;
A a2('F');
cout << endl;
cout << a1.getC1() << "," << a2.getC2() << endl;
a1.setC1('O');
a2.swap();
cout << a1.getC1() << "," << a1.getC2() << endl;
cout << a2.getC1() << "," << a2.getC2() << endl;
a1.swap();
cout << a1.getC1() << "," << a1.getC2() << endl;
}