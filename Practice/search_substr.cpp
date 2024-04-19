#include <iostream>
using namespace std;

bool prac(const char* str, const char* subStr)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        int j = 0;

        while(subStr[j] != '\0' && str[i + j] != '\0' && subStr[j] == str[i + j])
            j++;

        if(subStr[j] == '\0')
            return true;
    }

    return false;
}

void test(const char* str, const char* subStrFind, int& occ, int& index)
{
    index = -1;

    for(int i = 0; str[i] != '\0'; i++)
    {
        int j = 0;

        while(subStrFind[j] != '\0'&& str[i + j] != '\0' && subStrFind[j] == str[i + j])
            j++;

        if(subStrFind[j] == '\0')
        {
            if(index == -1)
                index = i;

            occ++;
        }
    }
}

bool SubStringExists(const char* str, const char* subStr)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        int j = 0;

        while (subStr[j] != '\0' && str[i + j] != '\0' && str[i + j] == subStr[j])
            j++;

        if (subStr[j] == '\0')
            return true;
    }

    return false;
}
int main()
{
    const char* str = "Pakistan Pak     pak PakiPak";
    const char* subStr = "pak";
    int occurence = 0;
    int firstIndex = 0;

    test(str, subStr, occurence, firstIndex);

    cout << "Occurences = " << occurence << endl;
    cout << "First index = " << firstIndex << endl;



    if(prac(str, subStr))
    {
        cout << "\n\n I am\n\n";
    }
    else
    {
        cout << "\n\nI am not\n\n";
    }

    return 0;
}



