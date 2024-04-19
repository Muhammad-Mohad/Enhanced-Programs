#include <iostream>
#include <fstream>
using namespace std;

int StrLen(const char*);                                    // to calculate length of strings
void StringConcatenate(char*, char*);                       // to join two strings
char** StringTokens(char*);                                 // separating every word of a string in the form of 2D array
void DisplayTokens(char**);                                 // displaying every word of a string vertically in the form of 2D array 
char* ReverseSentence(char*);                               // reversing the order of the words in a string
char** InputStringsFromFile(ifstream&, int&);               // retrieving the names of the students from the input file
void DisplayStringList(char**, int&);                       // displaying the names of the students
int CompareString(char*, char*);                            // compares which string is bigger or vice versa
void BubbleSort(char**, const int);                         // sorts the names of the students


int main()
{
    const int maxSize = 80;
    int numOfStrings = 0;

    char* str1 = new char[maxSize];
    char* str2 = new char[maxSize];
    char* updatedStr1 = nullptr;
    char** tokens = nullptr;
    char** studentsList = nullptr;

    ifstream inputFile("Data.txt");     // opening the input file


    // String Concatenation
    cout << "String Concatenation:\n\n";

    inputFile.getline(str1, maxSize - 1);
    cout << "String 1:      \"" << str1 << "\"" << endl;

    inputFile.getline(str2, maxSize - 1);
    cout << "String 2:      \"" << str2 << "\"" << endl;

    StringConcatenate(str1, str2);


    // Displaying Tokens of the string
    tokens = StringTokens(str1);
    cout << "\nTokens of String 1 are as follows:\n\n";
    DisplayTokens(tokens);


    // Displaying the reversed order words of sentence 
    updatedStr1 = ReverseSentence(str1);
    cout << "\nReverse sentence of String 1 is:      \"" << updatedStr1 << "\"" << endl;


    // Displaying the students list before sorting 
    studentsList = InputStringsFromFile(inputFile, numOfStrings);
    cout << "\n\nName of all the Students are:\n\n";
    DisplayStringList(studentsList, numOfStrings);


    // Displaying the students list after sorting
    BubbleSort(studentsList, numOfStrings);
    cout << "\n\nSorted List of Students:\n\n";
    DisplayStringList(studentsList, numOfStrings);



    // Deleting the dynamically allocated memory 
    for(int i = 0; i < numOfStrings; i++)
    {
        delete[] studentsList[i];
    }

    delete[] str1;
    delete[] str2;
    delete[] updatedStr1;
    delete[] tokens;
    delete[] studentsList;


    inputFile.close();      // closing the input file         

    return 0;
}


int StrLen(const char* str)
{
    int len = 0;

    while (str[len] != '\0')
    {
        len++;
    }

    return len;
}


void StringConcatenate(char* str1, char* str2)
{
    int lenStr1 = StrLen(str1);
    int i = 0;

    while (str2[i] != '\0')
    {
        str1[lenStr1 + i] = str2[i];
        i++;
    }

    str1[lenStr1 + i] = '\0';

    cout << "After Concatenation:" << endl;
    cout << "String 1:      \"" << str1 << "\"" << endl;
    cout << "String 2:      \"" << str2 << "\"" << endl;
}


char** StringTokens(char* str)
{
    int len = StrLen(str);
    int numOfTokens = 1;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            numOfTokens++;
        }
    }

    char** tokens = new char* [numOfTokens + 1];

    int tokenIndex = 0;
    int tokenStart = 0;
    int tokenLength = 0;

    for (int i = 0; i <= len; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            tokenLength = i - tokenStart;
            tokens[tokenIndex] = new char[tokenLength + 1];

            for (int j = 0; j < tokenLength; j++)
            {
                tokens[tokenIndex][j] = str[tokenStart + j];
            }

            tokens[tokenIndex][tokenLength] = '\0';
            
            tokenIndex++;
            tokenStart = i + 1;
        }
    }

    tokens[numOfTokens] = nullptr;

    return tokens;
}


void DisplayTokens(char** tokens)
{
    for (int i = 0; tokens[i] != nullptr; i++)
    {
        for (int j = 0; tokens[i][j] != '\0'; j++)
        {
            cout << tokens[i][j];
        }

        cout << endl;

        delete[] tokens[i];
    }
}


char* ReverseSentence(char* str)
{
    int len = StrLen(str);

    char* updatedStr1 = new char[len + 1];

    for(int i = 0; i <= len; i++)
    {
        updatedStr1[i] = str[i];
    }

    int start = 0;
    int end = len - 1;

    while(start < end)
    {
        char temp = updatedStr1[start];
        updatedStr1[start] = updatedStr1[end];
        updatedStr1[end] = temp;
        start++;
        end--;
    }

    start = 0;

    for(int i = 0; i <= len; i++)
    {
        if(updatedStr1[i] == ' ' || updatedStr1[i] == '\0')
        {
            end = i - 1;

            while(start < end)
            {
                char temp = updatedStr1[start];
                updatedStr1[start] = updatedStr1[end];
                updatedStr1[end] = temp;
                start++;
                end--;
            }

            start = i + 1;
        }
    }

    return updatedStr1;
}


char** InputStringsFromFile(ifstream& inputFile, int& size)
{
    if(inputFile.is_open())
    {
        inputFile >> size;
        inputFile.ignore(); 

        const int nameSize = 30;

        char** list = new char*[size + 1];
        int count = 0;

        while (count < size) 
        {
            char* buffer = new char[nameSize + 1];
            int i = 0;
            char ch;

            
            while ((ch = inputFile.get()) != '\n' && ch != EOF && i < nameSize)
            {
                buffer[i] = ch;
                i++;
            }
            
            buffer[i] = '\0';

            
            if (ch == '\n' || inputFile.eof())
            {
                list[count] = buffer;
                count++; 
            }
            else
            {
                delete[] buffer; 
                break; 
            }
        }

        list[count] = nullptr; 
        size = count; 

        inputFile.close();

        return list;
    }
    else
    {
        cout << "Error opening the file";
        exit(EXIT_FAILURE);
    }
}


void DisplayStringList(char** studentsList, int& size)
{
    for(int i = 0; i < size; i++)
    {
        cout << studentsList[i] << endl;
    }
}


int CompareString(char* str1, char* str2)
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



void BubbleSort(char** list, const int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(CompareString(list[j], list[j + 1]) == 1)
            {
                char* temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}