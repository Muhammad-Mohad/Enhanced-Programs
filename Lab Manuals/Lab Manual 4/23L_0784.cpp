#include <iostream>
#include <fstream>
// #define _CRTDBG_MAP_ALLOC
// #include <stdlib.h>
// #include <crtdbg.h>
using namespace std;

char** ReadStudentsListFromFile(int&);                          // retrieves the students name from the file
void PrintAllNames(char**, int&);                               // prints the students names
int FirstIndexOfSubString(char*, char*);                        // returns the index where substring is found
char** FindNameFromStudentsList(char**, char*);                 // finds that substring from the data and displays all the possible names containing it by using the above FirstIndexOfSubString function
void RemoveStudents(char**&, int&, char*);                      // removes the names with that specific substring and then displays the remaining names
void toLowerCase(char*);                                        // converts the alphabets to lower order to retrieve all the possible names 



int main()
{
    int size = 0;
    const int maxNameSize = 80;

    char** studentsList = nullptr;
    char** namesFound = nullptr;
    char* searchString = new char[maxNameSize];

    studentsList = ReadStudentsListFromFile(size);

    cout << "\nThe names of the students:\n\n";
    PrintAllNames(studentsList, size);

    cout << "\nEnter the substring to find in the file: ";
    cin.getline(searchString, maxNameSize - 1);

    namesFound = FindNameFromStudentsList(studentsList, searchString);

    RemoveStudents(studentsList, size, searchString);

    cout << "\nRemaining students after the removal are:\n\n";
    PrintAllNames(studentsList, size);


    // Deallocating memory
    for(int i = 0; i < size; i++)
    {
        delete[] studentsList[i];
    }

    delete[] studentsList;
    delete[] namesFound;
    delete[] searchString;

    // cout << "\n\nLeak Count = " << _CrtDumpMemoryLeaks() << endl;

    return 0;
    
}






char** ReadStudentsListFromFile(int& size)
{
    ifstream inputFile("StudentsList.txt"); 

    if(inputFile.is_open())
    {
        inputFile >> size;
        size+=1;
        inputFile.ignore();

        const int nameSize = 80;

        char** list = new char*[size + 1];
        char buffer[nameSize];
        int count = 0;

        while(inputFile.getline(buffer, nameSize - 1) && count <= size)
        {
            list[count] = new char[nameSize];

            int i = 0;

            while(buffer[i] != '\0' && i < nameSize - 1)
            {
                list[count][i] = buffer[i];
                i++;
            }

            list[count][i] = '\0';
            count++;
        }

        list[count] = nullptr;

        size = count;

        inputFile.close();

        return list;
    }
    else{
        cout << "\nError Opening the File";
        exit(EXIT_FAILURE);
    }
}

void PrintAllNames(char** studentsList, int& size)
{
    for(int i = 0; i < size; i++)
    {
        cout << studentsList[i] << endl;
    }
}

int FirstIndexOfSubString(char* myStr, char* strToFind)
{
    if(myStr == nullptr || strToFind == nullptr)
    {
        return -1;
    }

    int myStrLen = 0;
    int strToFindLen = 0;


    while(myStr[myStrLen] != '\0')
    {
        myStrLen++;
    }

    while(strToFind[strToFindLen] != '\0')
    {
        strToFindLen++;
    }

    for(int i = 0; i <= myStrLen - strToFindLen; i++) 
    {
        int j = 0;

        while(j < strToFindLen && myStr[i + j] == strToFind[j])
        {
            j++;
        }

        if(j == strToFindLen)
        {
            return i;

        }
    }

    return -1;
}


char** FindNameFromStudentsList(char** list, char* searchString)
{
    toLowerCase(searchString);

    cout << "\nNames found:\n\n";

    int studentsFound = 0;
    const int maxStudents = 100;

    char** result = new char*[maxStudents];

    for(int i = 0; list[i] != nullptr; i++)
    {
        const int maxNameSize = 50;

        char* name = list[i];
        char nameLower[maxNameSize];

        int j = 0;

        while(name[j] != '\0')
        {
            nameLower[j] = name[j];

            if(name[j] >= 'A' && name[j] <= 'Z')
            {
                nameLower[j] += 32;
            }
            j++;
        }

        nameLower[j] = '\0';

        if(FirstIndexOfSubString(nameLower, searchString) != -1)
        {
            result[studentsFound] = list[i];
            studentsFound++;
        }
    }

    result[studentsFound] = nullptr;

    return result;
}

void RemoveStudents(char**& studentsList, int& size, char* searchString)
{
    int removeCount = 0;
    const int maxNameSize = 80;

    char** newList = new char*[size];

    for(int i = 0; i < size; i++)
    {
        char* name = studentsList[i];
        char nameLower[maxNameSize];

        int j = 0;

        while(name[j] != '\0')
        {
            nameLower[j] = name[j];

            if(name[j] >= 'A' && name[j] <= 'Z')
            {
                nameLower[j] += 32;
            }
            j++;
        }

        nameLower[j] = '\0';

        if(FirstIndexOfSubString(nameLower, searchString) != -1)
        {
            cout << "-  " << studentsList[i] << endl;

            delete[] studentsList[i];

            removeCount++;
        }
        else
        {
            newList[i - removeCount] = studentsList[i];
        }
    }

    delete[] studentsList;
    studentsList = newList;
    size -= removeCount;
}

void toLowerCase(char* str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
}


