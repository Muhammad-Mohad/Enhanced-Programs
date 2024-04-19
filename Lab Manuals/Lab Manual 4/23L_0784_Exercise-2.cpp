#include <iostream>
using namespace std;

int GetCharacterCount(char*, char);

int main()
{
    const int size = 80;
    char* str = new char[size];
    char ch = '\0';
    int count = 0;

    cout << "Enter the string: ";
    cin.getline(str, size - 1);

    cout << "Enter the character to search in the string: ";
    cin >> ch;

    count = GetCharacterCount(str, ch);

    cout << "Total number of occurances of '" << ch << "' are: " << count << endl;

    return 0;
}

int GetCharacterCount(char* myString, char c)
{
    int count = 0;
    int i = 0;

    while(myString[i] != '\0')
    {
        if(myString[i] == c)
        {
            count++;
        }

        i++;
    }

    return count;
}