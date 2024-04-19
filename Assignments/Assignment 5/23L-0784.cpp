#include <iostream>
#include <fstream>
using namespace std;

const int maxSize = 4;

class Helper
{
    public:
        // Helper Functions
        friend bool SubStringExists(const char*, const char*);
        static int StringLength(char*);
        static char* GetStringFromBuffer(char*);
        static void StringCopy(char*&, char*&);
};


class EvaluationReport
{
    private:
        char* rollNumber;
        char* firstName;
        char* lastName;

        int quiz[maxSize];
        int assignment[maxSize];
        int total;

        // For Update Statistics
        static int allQuizzes[maxSize];
        static int allAssignment[maxSize];
        static int maxOfQuizzes[maxSize];
        static int maxOfAssignments[maxSize];
        static int minOfQuizzes[maxSize];
        static int minOfAssignments[maxSize];
        static float avgOfQuizzes[maxSize];
        static float avgOfAssignments[maxSize];

        // For Shared Data
        static int totalStudents;
        static int totalQuizzes;
        static int totalAssignments;
        static int sharedQuizzesData[maxSize];
        static int sharedAssignmentsData[maxSize];
        static int sharedTotal;
        static void ReadStaticDataFromFile(ifstream&);

    public:
        // Constuctor, Destructor, Assignment Operator and Copy Constructor
        EvaluationReport();
        ~EvaluationReport();
        EvaluationReport& operator = (EvaluationReport&);
        EvaluationReport(const EvaluationReport&);

        // Global Functions as Friends
        friend EvaluationReport* ReadDataFromFile(ifstream&);
        friend void PrintAll(EvaluationReport*);
        friend EvaluationReport** SearchStudentsByKeyWord(EvaluationReport*, const char*);
        friend EvaluationReport* SearchStudentByRollNumber(EvaluationReport*, const char*);
        friend void SortListByTotal(EvaluationReport*&);
        friend void PrintStudentFound(EvaluationReport*);
        friend void UpdateStatistics(EvaluationReport*);
        friend void PrintStats(EvaluationReport*);

        // Class Functions
        void ReadDataFromFile(ifstream&);
        void PrintListView();
};


// Static Members Initialization
float EvaluationReport::avgOfQuizzes[maxSize] = { 0 };
float EvaluationReport::avgOfAssignments[maxSize] = { 0 };
int EvaluationReport::allQuizzes[maxSize] = { 0 };
int EvaluationReport::allAssignment[maxSize] = { 0 };
int EvaluationReport::maxOfQuizzes[maxSize] = { 0 };
int EvaluationReport::maxOfAssignments[maxSize] = { 0 };
int EvaluationReport::minOfQuizzes[maxSize] = { 0 };
int EvaluationReport::minOfAssignments[maxSize] = { 0 };
int EvaluationReport::totalStudents = 0;
int EvaluationReport::totalQuizzes = 0;
int EvaluationReport::totalAssignments = 0;
int EvaluationReport::sharedQuizzesData[maxSize] = { 0 };
int EvaluationReport::sharedAssignmentsData[maxSize] = { 0 };
int EvaluationReport::sharedTotal = 0;



// Prototypes of Global Functions
EvaluationReport* ReadDataFromFile(ifstream&);
void PrintAll(EvaluationReport*);
EvaluationReport** SearchStudentsByKeyWord(EvaluationReport*, const char*);
EvaluationReport* SearchStudentByRollNumber(EvaluationReport*, const char*);
bool SubStringExists(const char*, const char*);
void PrintAllFiltered(EvaluationReport**);
void SortListByTotal(EvaluationReport*&);
void PrintStudentFound(EvaluationReport*);
void UpdateStatistics(EvaluationReport*);
void PrintStats(EvaluationReport*);




int main()
{
    ifstream inputFile("GradeSheet.txt");

    EvaluationReport* students = ReadDataFromFile(inputFile);

    if (students != nullptr)
    {
        cout << "\nEvaluation Report:\n";

        cout << "\n\nDisplaying Statistics:\n\n";
        UpdateStatistics(students);
        PrintStats(students);

        cout << "\n\nDisplaying Students:\n\n";
        PrintAll(students);


        const char keyWord[] = "43";

        EvaluationReport** foundStudents = SearchStudentsByKeyWord(students, keyWord);

        cout << "\n\n\nStudents matching the keyword \"" << keyWord << "\":\n\n\n";

        PrintAllFiltered(foundStudents);

        cout << "\n\n\nSorted List Of Students:\n\n\n";

        SortListByTotal(students);
        PrintAll(students);

        const char find1[] = "15L-1234";

        cout << "\n\nEnter Roll Number of the Student:\t" << find1;

        EvaluationReport* student1 = SearchStudentByRollNumber(students, find1);
        PrintStudentFound(student1);

        const char find2[] = "15L-4023";

        cout << "\n\nEnter Roll Number of the Student:\t" << find2;

        EvaluationReport* student2 = SearchStudentByRollNumber(students, find2);
        PrintStudentFound(student2);


        delete[] foundStudents;
        delete[] students;

        inputFile.close();
    }

    return 0;
}





// Helper Functions Definitions
void Helper::StringCopy(char*& dest, char*& src)
{
    char* tempDest = dest;

    for (char* tempSrc = src; *tempSrc != '\0'; tempSrc++, tempDest++)
        *tempDest = *tempSrc;

    *tempDest = '\0';
}


char* Helper::GetStringFromBuffer(char* buffer)
{
    int strLen = StringLength(buffer);
    char* str = nullptr;

    if (strLen > 0)
    {
        str = new char[strLen + 1];
        StringCopy(str, buffer);
    }
    return str;
}


int Helper::StringLength(char* str)
{
    int stringLen = 0;
    for (char* temp = str; *temp != '\0'; temp++)
        stringLen++;

    return stringLen;
}






// Global Functions Definitions
EvaluationReport* ReadDataFromFile(ifstream& inputFile)
{
    if (inputFile)
    {
        EvaluationReport::ReadStaticDataFromFile(inputFile);

        EvaluationReport* students = new EvaluationReport[EvaluationReport::totalStudents];

        for (int i = 0; i < EvaluationReport::totalStudents; i++)
            students[i].ReadDataFromFile(inputFile);

        return students;
    }

    else
        return nullptr;
}

void PrintAll(EvaluationReport* students)
{
    cout << "Roll No." << "\t" << "Name" << "\t\t\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4" << "\t" << "A1" << "\t" << "A2" << "\t" << "A3" << "\t" << "A4" << "\t" << "Total" << endl << endl;

    for (int i = 0; i < EvaluationReport::totalStudents; i++)
        students[i].PrintListView();
}

void PrintAllFiltered(EvaluationReport** students)
{
    cout << "Roll No." << "\t" << "Name" << "\t\t\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4" << "\t" << "A1" << "\t" << "A2" << "\t" << "A3" << "\t" << "A4" << "\t" << "Total" << endl << endl;

    if (students == nullptr || *students == nullptr)
    {
        cout << "\nNo Students Found\n";
        return;
    }

    for (int i = 0; students[i] != nullptr; i++)
        students[i]->PrintListView();
}

EvaluationReport** SearchStudentsByKeyWord(EvaluationReport* students, const char* str)
{
    EvaluationReport** foundStudents = new EvaluationReport* [EvaluationReport::totalStudents];
    int count = 0;

    for (int i = 0; i < EvaluationReport::totalStudents; i++)
    {
        if (SubStringExists(students[i].rollNumber, str) || SubStringExists(students[i].firstName, str) || SubStringExists(students[i].lastName, str))
        {
            foundStudents[count] = &students[i];
            count++;
        }
    }

    EvaluationReport** filteredStudents = new EvaluationReport* [count + 1];

    for (int i = 0; i < count; i++)
        filteredStudents[i] = foundStudents[i];

    filteredStudents[count] = nullptr;

    delete[] foundStudents;

    return filteredStudents;
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

void SortListByTotal(EvaluationReport*& students)
{
    for (int i = 0; i < EvaluationReport::totalStudents; i++)
    {
        for (int j = 0; j < EvaluationReport::totalStudents - 1; j++)
        {
            if (students[j].total > students[j + 1].total)
            {
                EvaluationReport temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

EvaluationReport* SearchStudentByRollNumber(EvaluationReport* students, const char* rollNumber)
{
    for (int i = 0; i < EvaluationReport::totalStudents; i++)
    {
        const char* studentRollNumber = students[i].rollNumber;
        
        int j = 0;

        while (rollNumber[j] != '\0' && studentRollNumber[j] != '\0' && rollNumber[j] == studentRollNumber[j])
            j++;

        if (rollNumber[j] == '\0' && studentRollNumber[j] == '\0')
            return &students[i];
    }

    return nullptr;
}


void PrintStudentFound(EvaluationReport* student)
{
    if (student == nullptr)
    {
        cout << "\n\nStudent Not Found\n\n";
    }

    else
    {
        cout << "\n\nStudents Information:\n\n";
        cout << "Roll No:\t\t" << student->rollNumber;
        cout << "\nName:\t\t\t" << student->firstName << " " << student->lastName;
        cout << "\nQuizzes Marks:\n\t\t\t";

        for (int i = 0; i < maxSize; i++)
        {
            cout << "Q" << i + 1 << ":\t" << student->quiz[i] << "/" << EvaluationReport::sharedQuizzesData[i];
            if (i < maxSize - 1)
                cout << "\n\t\t\t";
        }

        cout << "\nAssignment Marks:\n\t\t\t";

        for (int i = 0; i < maxSize; i++)
        {
            cout << "A" << i + 1 << ":\t" << student->assignment[i] << "/" << EvaluationReport::sharedAssignmentsData[i];
            if (i < maxSize - 1)
                cout << "\n\t\t\t";
        }

        cout << "\nTotal:\t\t\t\t" << student->total << "/" << EvaluationReport::sharedTotal << endl;
    }
}

void UpdateStatistics(EvaluationReport* students)
{
    for (int i = 0; i < maxSize; i++)
    {
        for (int j = 0; j < EvaluationReport::totalStudents; j++)
        {
            EvaluationReport::allQuizzes[i] += students[j].quiz[i];
            EvaluationReport::allAssignment[i] += students[j].assignment[i];
        }

        EvaluationReport::avgOfQuizzes[i] = static_cast<float>(EvaluationReport::allQuizzes[i]) / EvaluationReport::totalStudents;
        EvaluationReport::avgOfAssignments[i] = static_cast<float>(EvaluationReport::allAssignment[i]) / EvaluationReport::totalStudents;
    }

    for (int i = 0; i < maxSize; i++)
    {

        EvaluationReport::minOfQuizzes[i] = EvaluationReport::maxOfQuizzes[i] = students[0].quiz[i];
        EvaluationReport::minOfAssignments[i] = EvaluationReport::maxOfAssignments[i] = students[0].assignment[i];

        for (int j = 1; j < EvaluationReport::totalStudents; j++)
        {
            if (students[j].quiz[i] < EvaluationReport::minOfQuizzes[i])
                EvaluationReport::minOfQuizzes[i] = students[j].quiz[i];
            if (students[j].quiz[i] > EvaluationReport::maxOfQuizzes[i])
                EvaluationReport::maxOfQuizzes[i] = students[j].quiz[i];

            if (students[j].assignment[i] < EvaluationReport::minOfAssignments[i])
                EvaluationReport::minOfAssignments[i] = students[j].assignment[i];
            if (students[j].assignment[i] > EvaluationReport::maxOfAssignments[i])
                EvaluationReport::maxOfAssignments[i] = students[j].assignment[i];
        }
    }
}

void PrintStats(EvaluationReport* students)
{
    cout << "\t\tQ1\tQ2\tQ3\tQ4\tA1\tA2\tA3\tA4\n";

    cout << "Total:\t\t";

    for (int i = 0; i < maxSize; i++)
        cout << EvaluationReport::sharedQuizzesData[i] << "\t";

    for (int i = 0; i < maxSize; i++)
        cout << EvaluationReport::sharedAssignmentsData[i] << "\t";

    cout << "\nMaximum:\t";

    for (int i = 0; i < maxSize; i++)
        cout << EvaluationReport::maxOfQuizzes[i] << "\t";

    for (int i = 0; i < maxSize; i++)
        cout << EvaluationReport::maxOfAssignments[i] << "\t";

    cout << "\nMinimum:\t";

    for (int i = 0; i < maxSize; i++)
        cout << EvaluationReport::minOfQuizzes[i] << "\t";

    for (int i = 0; i < maxSize; i++)
        cout << EvaluationReport::minOfAssignments[i] << "\t";

    cout << "\nAverage:\t";

    for (int i = 0; i < maxSize; i++)
        cout << EvaluationReport::avgOfQuizzes[i] << "\t";

    for (int i = 0; i < maxSize; i++)
        cout << EvaluationReport::avgOfAssignments[i] << "\t";

    cout << "\n\n";
}









// Class Functions Definitions
EvaluationReport::EvaluationReport()
{
    rollNumber = firstName = lastName = nullptr;
    total = 0;

    for (int i = 0; i < maxSize; i++)
    {
        quiz[i] = 0;
        assignment[i] = 0;
    }
}

EvaluationReport::~EvaluationReport()
{
    if(rollNumber != nullptr)
        delete[] rollNumber;
    if(firstName != nullptr)
        delete[] firstName;
    if(lastName != nullptr)
        delete[] lastName;
}



void EvaluationReport::PrintListView()
{
    cout << rollNumber << "\t" << firstName << " " << lastName << "\t\t" << quiz[0] << "\t" << quiz[1] << "\t" << quiz[2] << "\t" << quiz[3] << "\t" << assignment[0] << "\t" << assignment[1] << "\t" << assignment[2] << "\t" << assignment[3] << "\t" << total << endl;
}

EvaluationReport& EvaluationReport::operator = (EvaluationReport& copy)
{
    if (this != &copy)
    {
        delete[] rollNumber;
        delete[] firstName;
        delete[] lastName;

        total = copy.total;

        rollNumber = Helper::GetStringFromBuffer(copy.rollNumber);
        firstName = Helper::GetStringFromBuffer(copy.firstName);
        lastName = Helper::GetStringFromBuffer(copy.lastName);

        for (int i = 0; i < maxSize; i++)
        {
            quiz[i] = copy.quiz[i];
            assignment[i] = copy.assignment[i];
        }
    }

    return *this;
}

EvaluationReport::EvaluationReport(const EvaluationReport& copy)
{
    total = copy.total;

    rollNumber = Helper::GetStringFromBuffer(copy.rollNumber);
    firstName = Helper::GetStringFromBuffer(copy.firstName);
    lastName = Helper::GetStringFromBuffer(copy.lastName);

    for (int i = 0; i < maxSize; i++)
    {
        quiz[i] = copy.quiz[i];
        assignment[i] = copy.assignment[i];
    }
}

void EvaluationReport::ReadDataFromFile(ifstream& inputFile)
{
    total = 0;

    const int tempSize = 20;
    char temp[tempSize];

    inputFile >> temp;
    rollNumber = Helper::GetStringFromBuffer(temp);

    inputFile >> temp;
    firstName = Helper::GetStringFromBuffer(temp);

    inputFile >> temp;
    lastName = Helper::GetStringFromBuffer(temp);

    for (int i = 0; i < maxSize; i++)
    {
        inputFile >> quiz[i];
        total += quiz[i];
    }

    for (int i = 0; i < maxSize; i++)
    {
        inputFile >> assignment[i];
        total += assignment[i];
    }
}

void EvaluationReport::ReadStaticDataFromFile(ifstream& inputFile)
{
    inputFile >> totalStudents;
    inputFile >> totalQuizzes;
    inputFile >> totalAssignments;

    for (int i = 0; i < maxSize; i++)
    {
        inputFile >> sharedQuizzesData[i];
        sharedTotal += sharedQuizzesData[i];
    }

    for (int i = 0; i < maxSize; i++)
    {
        inputFile >> sharedAssignmentsData[i];
        sharedTotal += sharedAssignmentsData[i];
    }
}









