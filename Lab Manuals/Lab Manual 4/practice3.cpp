#include <iostream>
using namespace std;

char* trim(char*);
char* trimRev(char*);

int main()
{
    char* str = new char[50];
    char* trimmed = nullptr;
    
    cout << "Enter string: ";
    cin.getline(str, 49);

    cout << "Trimmed: ";

    trimmed = trim(str);

    cout << "\"" << trimmed << "\"" << endl;


    delete[] str;
    delete[] trimmed;

    return 0;
}

char* trim(char* str)
{
    int length = 0;

    while(str[length] != '\0')
        length++;

    int index = 0;

    while(index < length && str[index] ==' ')
        index++;

    int newIndex = 0;

    while(index < length)
    {
        str[newIndex] = str[index];
        newIndex++;
        index++;
    }

    str[newIndex] = '\0';

    return str;
        
}

char* trimRev(char* str)
{
    int length = 0;

    while(str[length] != '\0')
        length++;

    int index = length - 1;

    while(index >= 0 && str[index] ==' ')
        index--;


    str[index + 1] = '\0';

    return str;
        
}