#include<iostream>
using namespace std;

class ComplexNumber
{
	
	//friend functions can directly access private data of class
	friend ostream& operator<<(ostream&, const ComplexNumber&);// overloaded stream insertion operator
	friend istream& operator>>(istream&, ComplexNumber&);// overloaded stream extraction operator
	//These functions are friends of our class

private:
	int real;
	int imaginary;
public:
	ComplexNumber();
	ComplexNumber(int, int);
	void Print();
	
};

ComplexNumber::ComplexNumber()
{
	real = imaginary = 0;
}
ComplexNumber::ComplexNumber(int r, int i)
{
	real = r;
	imaginary = i;
}

//operator<< is a global function. This is not a member function of class
//overloaded stream insertion operator
ostream& operator<<(ostream& out, const ComplexNumber& obj)
{
	out << obj.real;		//Can we read/write private data in this function?
	if (obj.imaginary >= 0)
		out << "+";
	out << obj.imaginary << "i";
	return out;	// to enable cascading
}

//operator>> is a global function. This is not a member function of class
//overloaded stream extraction operator
istream& operator>>(istream& in, ComplexNumber& obj)
{
	cout<<"Input Real:\t";
	in >> obj.real;			//Can we read/write private data in this function?
	cout<<"Input Imaginary:\t";
	in >> obj.imaginary;
	return in;	// to enable cascading
}

int main()
{
	ComplexNumber c1, c2, c3;
	cout << "Enter c1, c2 and c3 (real and imaginary parts) one by one:\n";
	
	//Input(c1);
	//cin>>c1;	//cin.operator>>(c1); operator>>(cin,c1);
	//cout<<c1;

	cin >> c1 >> c2 >> c3;		//cin is an object of istream class and is attached to keyboard
	//cin>>c1--> cin>>c2 --> cin>>c3
	// cin.operator>>(c1) VS operator>>(cin,c1) ???
	
	cout << "c1 = " << c1 << "\nc2 = " << c2 << "\nc3 = " << c3 << endl;	//cout is an object of ostream class and is attached to console.

	//we use standard cin, cout objects without making their copies.

	//what if we want c2 = 2 + c1 //int.operator+(c1)
	//operator+(int, compNum)
	//c1 + 2 (c1.op+(2) Member function) ... 2 + c1(2.op+(c1)--> op+(2,c1) Non member global function) 	
	//lhsObj.operatorXYZ(rhsObj)
	//operatorXYZ(lhsObj, rhsObj);

}