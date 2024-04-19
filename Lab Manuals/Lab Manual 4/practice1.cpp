#include <iostream>
using namespace std;

char* FindAndReplaceString(char*, char*, char*);
int StrLength(const char*);
bool StringCompare(const char*, const char*, int);

int main()
{
    const int maxSize = 100;

    char* str = new char[maxSize];
    char* toFind = new char[maxSize];
    char* toReplace = new char[maxSize];
    char* newString = nullptr;

    cout << "String: ";
    cin.getline(str, maxSize - 1);

    cout << "toFind: ";
    cin.getline(toFind, maxSize - 1);

    cout << "toReplace: ";
    cin.getline(toReplace, maxSize - 1);
    cout << endl;

    newString = FindAndReplaceString(str, toFind, toReplace);

    cout << "New String: " << newString << endl;

    delete[] newString;
    delete[] str;
    delete[] toFind;
    delete[] toReplace;

    return 0;
}

char* FindAndReplaceString(char* str, char* toFind, char* toReplace)
{
    int strLen = StrLength(str);
    int toFindLen = StrLength(toFind);
    int toReplaceLen = StrLength(toReplace);

    int occurrence = 0;

    for(int i = 0; i <= strLen - toFindLen; i++)
    {
        if(StringCompare(&str[i], toFind, toFindLen))
        {
            occurrence++;
            i += toFindLen - 1;
        }
    }

    int resultLen = strLen + occurrence * (toReplaceLen - toFindLen);

    char* result = new char[resultLen + 1];

    int resultIndex = 0;

    for(int i = 0; i < strLen; i++)
    {
        if(StringCompare(&str[i], toFind, toFindLen))
        {

            for(int j = 0; j < toReplaceLen; j++)
            {
                result[resultIndex++] = toReplace[j];
            }

            i += toFindLen - 1;
        }

        else{
            result[resultIndex++] = str[i];
        }
    }

    result[resultIndex] = '\0';

    return result;
    
}

int StrLength(const char* str)
{
    int len = 0;

    while(str[len] != '\0')
        len++;

    return len;
}

bool StringCompare(const char* str1, const char* str2, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(str1[i] != str2[i])
        {
            return false;
        }
    }

    return true;
}