#include <iostream>
using namespace std;

class MyString
{
	private:
		char* str;
		int length;

		static int GetStringFromBuffer(const char*, char*&);
		static char* Concatenate(const char*, const char*);
		static int StringLength(const char*);
		static int Compare(const char*, const char*);

	public:
		MyString();
		MyString(char*, int);
		~MyString();

		MyString(const MyString&);
		MyString& operator=(const MyString&);

		friend ostream& operator<<(ostream&, MyString&);
		friend istream& operator>>(istream&, MyString&);

		MyString operator+(const MyString);
		bool operator<(MyString);	
		bool operator!();
		char& operator[](int);
		MyString operator()(int, int);
		operator const char*() const;  
};

MyString::MyString()
{
	str = new char[1];
	str[0] = '\0';
	length = 0;
}

MyString::operator const char*() const
{
	return str;
}

MyString::MyString(char* ch, int  len)
{
	str = new char[len + 1];

	for(int i = 0; i < len; i++)
		str[i] = ch[i];

	str[len] = '\0';

	length = len;
}

MyString::MyString(const MyString& string) 
{
    length = string.length;

    str = new char[length + 1];

    for (int i = 0; i < length; i++)
        str[i] = string.str[i];
		
    str[length] = '\0';
}


MyString::~MyString()
{
	delete[] str;
}

bool MyString::operator!()
{
	return ((*str == '\0') && !length);
}

ostream& operator<<(ostream& out, MyString& string)
{
	for(int i = 0; i < string.length; i++)
		out << string.str[i];

	return out;
}

istream& operator>>(istream& in, MyString& string)
{
	const int size = 50;
	char buffer[size];

	in.getline(buffer, size - 1);

	delete[] string.str;

	string.length = MyString::GetStringFromBuffer(buffer, string.str);

	return in;
}

MyString& MyString::operator=(const MyString& string)
{
	if(this != &string)
	{
		delete[] str;

		int len = string.length;

		str = new char[len + 1];

		for(int i = 0; i < len; i++)
			str[i] = string.str[i];

		str[len] = '\0';

		length = len;
	}
	
	return *this;
}

int MyString::GetStringFromBuffer(const char* buffer, char*& str)
{
	int length = StringLength(buffer);

	str = new char[length + 1];

	for(int i = 0; i < length; i++)
		str[i] = buffer[i];

	str[length] = '\0';

	return length;
}

char* MyString::Concatenate(const char* str1, const char* str2) 
{
    int len1 = StringLength(str1);
    int len2 = StringLength(str2);

    char* result = new char[len1 + len2 + 1];

    int index = 0;

    for (int i = 0; i < len1; i++)
        result[index++] = str1[i];

    for (int i = 0; i < len2; i++)
        result[index++] = str2[i];

    result[index] = '\0';

    return result;
}

int MyString::Compare(const char* str1, const char* str2)
{
	while(*str1 != '\0' && *str2 != '\0') 
	{
		if(*str1 > *str2) 
			return 1; 

		else if(*str1 < *str2)
			return -1;

		str1++;
		str2++;
	}

	if(*str1 == '\0' && *str2 == '\0') 
		return 0;

	else if(*str1 == '\0')
		return -1;

	else
		return 1;
}

int MyString::StringLength(const char* str) 
{
    int len = 0;

    while (str[len] != '\0')
        len++;

    return len;
}

MyString MyString::operator+(const MyString string) 
{
    char* newStr = Concatenate(str, string.str);

    MyString result(newStr, length + string.length);

    delete[] newStr;
	
    return result;
}

bool MyString::operator<(MyString string)
{
	int check = Compare(str, string.str);

	if(check == -1)
		return true;
	else
		return false;
}	

char& MyString::operator[](int index)
{
	if(index > 0 && index < length)
		return str[index];

	else
	{
		cout << "\n\nIndex Out of Bounds. Displaying the First Character of the String.\n\n";
		return str[0];
	}
}

MyString MyString::operator()(int start, int len)
{
    if (start < 0)
        start = 0;

    if(len < 0)
        len = 0;

    if(start + len > length)
        len = length - start;

    char* substr = new char[len + 1]; 

    for(int i = 0; i < len; i++)
        substr[i] = str[start + i];
    
    substr[len] = '\0';

    MyString result(substr, len);

    delete[] substr;

    return result;
}



int main()
{
	MyString str1, str2, str3, str4;
	
	if(!str1)
	{
		cout << "String 1 is Empty.\n";
		cout <<"Str 1 = " << str1 << endl << endl << endl;
	}
	
	cout << "Enter String 1:\t";
	cin >> str1;


	cout << "Enter String 2:\t";
	cin >> str2;
		

	cout << "\n\n\nUser Entered:\n";
	cout << "String 1 = " << str1 << endl;
	cout << "String 2 = " << str2 << endl << endl << endl;


	cout << "Before str1 = str1; str1 = " << str1 << endl;
	str1 = str1;
	cout << "After str1 = str1, str1 = " << str1 << endl << endl << endl;


	cout << "Before str4 = str3 = str1+str2\n";
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
    cout << "str4 = " << str4 << endl;

	str4 = str3 = str1 + str2;

	cout << "\n\n\nAfter str4 = str3 = str1+str2\n";
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	cout << "\n\n\nEnter String 3:\t";
	cin >> str3;

	cout << "\n\n\nEnter String 4:\t";
	cin >> str4;

	
	cout << "\n\n\nstr3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	if(str3 < str4)
		cout << "String 3 is Less than String 4.\n";
	else
		cout << "String 3 is NOT Less than String 4.\n";

	MyString str5 = str1 + str2;
	cout << "\n\n\nStr5:\t" << str5 << endl;
	cout << "Str5[7]:\t" << str5[7] << endl;
	str5[7] = '$';

	cout << "\n\nStr5:\t" << str5 << endl;

	cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl;
    
    return 0;
}

