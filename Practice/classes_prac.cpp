//TO DO: Comment Assignment operator and Copy Constructor and check what built-in functioanlity does.
#include<iostream>
using namespace std;

class Rectangle{
		private:
			int* lenght;
			int* width;
		public:
			Rectangle(int l = 0, int w = 0)
			{
				cout << "\n\n\nConstructor Called for "<<this<<" with parameters " << l << " and " << w << "\n\n\n";
				lenght = new int(l);
				width = new int (w);
			}
			Rectangle(const Rectangle&);
			~Rectangle();
			void Print();
			const Rectangle& operator=(const Rectangle&);	
			void SetValues(int, int);
			Rectangle GetRotatedRectangle(){
				cout << "I am inside GetRotatedRectangle()" << endl;
				Rectangle temp(*width, *lenght);
				cout << "I am exiting GetRotatedRectangle()" << endl;
				return temp;
			}
};
//Rectangle::Rectangle(const Rectangle rhs) ... this is Syntax error... infinite Copy Constructor Calls
// Homework: Comment this Copy Constructor and check behavior of Built-In Copy constructor
Rectangle::Rectangle(const Rectangle& rhs)
{
	cout<<"Copy Constructor Called for "<<this<<" = "<<&rhs<<endl;
	lenght = new int( *rhs.lenght);
	width = new int ( *rhs.width);
}
Rectangle::~Rectangle()
{
	cout << "Destructor Called for "<<this<<" rectangle "<<*lenght<<" X "<<*width<<"\n\n";
	if(lenght != 0) delete lenght;
	if(width != 0) delete width;
}
// Homework: Comment this assignment operator and check behavior of Built-In function
const Rectangle& Rectangle::operator=(const Rectangle& rhs)
{
	cout<<"Overloaded Assignment Operator Called for "<<this<<" = "<<&rhs<<endl;

	if( &rhs != this )	//Avoid self-assignment
	{
		//De-allocate previous memory and allocate new memory IF REQUIRED
		*lenght = *rhs.lenght;
		*width = *rhs.width;
	}
	return *this;
}
void Rectangle::Print()
{
	cout << *lenght << " X " << *width<<endl<<endl;
}
void Rectangle::SetValues(int l , int w)
{
	*lenght = l;
	*width = w;
}
int main()
{
	{
		Rectangle r1(2, 3);
		Rectangle r2;

		r2 = r1.GetRotatedRectangle();
		cout << "Line after GetRotatedRectangle()" << endl;
		cout << "r2:\t";
		r2.Print();		
		r2.SetValues(200,300);
		cout << "r2:\t";
		r2.Print();		
		cout << "\n\n\n objects are going out of scope...\n\n\n";
		//Comment Copy Constructor and Assignment Operator and check what built-in Copy Constructor does?
	}
}