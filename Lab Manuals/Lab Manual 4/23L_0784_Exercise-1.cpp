#include <iostream>
using namespace std;

int StringLength(char*);

int main()
{
    // char charArray[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
    // cout << charArray << endl;

    // // char myStr1[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
    // // char myStr1[] = "Hello World";
    // char myStr1[20] = "Hello World";
    // cout << myStr1 << endl;

    // int len1 = StringLength(myStr1);

    // cout << len1 << endl;

    char myStr1[5] = "Helo";
    cout << "Initial String:\t" << myStr1 << endl;

    int len = 0;
    for(; myStr1[len] != '\0'; len++);
    cout << "Length of myStr1:\t" << len << endl << endl << endl;

    cout << "Enter another string of size 4: ";
    cin >> myStr1;

    cout << "String entered by the user is: " << myStr1 << endl;

    for(len = 0; myStr1[len] != '\0'; len++);
    cout << "Length of myStr1:\t" << len << endl << endl << endl;
    
    cout << "Program us going to terminate.\n"; 

    return 0;
}

int StringLength(char* str)
{
    int i = 0;
    int len = 0;

    while(str[i] != '\0')
    {
        len++;
        i++;
    }

    return len;
}