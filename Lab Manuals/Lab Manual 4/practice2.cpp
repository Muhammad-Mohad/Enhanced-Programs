#include <iostream>
using namespace std;

char* func(char*, char, char);
char* funcX(char*, char);

int main()
{
    char* str = new char[50];
    char* newStr = new char[50];
    char* strX = new char[50];
    char ch1;
    char ch2;

    cout << "Input String: ";
    cin.getline(str, 49);

    cout << "Character to Find: ";
    cin >> ch1;

    // cout << "Character to Replace: ";
    // cin >> ch2;

    // newStr = func(str, ch1, ch2);
    // cout << endl;

    // cout << "Modified String: " << newStr << endl;

    strX = funcX(str, ch1);
    cout << endl;

    cout << "Deleted: " << strX << endl;

    return 0;
}

char* func(char* str, char ch1, char ch2)
{
    int i = 0;

    while(str[i] != '\0')
    {
        if(str[i] == ch1)
        {
            str[i] = ch2;
        }
        i++;
    }

    return str;
}

char* funcX(char* str, char ch1)
{
    int i = 0, j = 0;

    while(str[i] != '\0')
    {
        if(str[i] != ch1)
        {
            str[j] = str[i];
            j++;
        }
        i++;
    }

    str[j]  = '\0';

    return str;

}