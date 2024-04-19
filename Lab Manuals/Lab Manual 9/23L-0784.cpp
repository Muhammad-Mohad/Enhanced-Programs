#include <iostream>
using namespace std;

int StringLength(const char* str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void StringCopy(char* dest, const char* src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

class Person
{
private:
    char* first_name;
    char* last_name;

protected:
    int age;

public:
    Person(const char* fName = nullptr, const char* lName = nullptr, int Age = 0)
    {
        if (fName != nullptr)
        {
            first_name = new char[StringLength(fName) + 1];
            StringCopy(first_name, fName);
        }
        else
            first_name = nullptr;

        if (lName != nullptr)
        {
            last_name = new char[StringLength(lName) + 1];
            StringCopy(last_name, lName);
        }
        else
            last_name = nullptr;

        age = Age;

        cout << "\nPerson() Called\n";
    }

    ~Person()
    {
        delete[] first_name;
        delete[] last_name;

        cout << "\n~Person() Called\n";
    }

    void PrintInfo()
    {
        cout << endl << first_name << " " << last_name << " is " << age << " years old.\n";
    }

    const char* GetFirstName()
    {
        return first_name;
    }

    const char* GetLastName()
    {
        return last_name;
    }
};

class Student : public Person
{
private:
    float cgpa;

public:
    Student(const char* fName = nullptr, const char* lName = nullptr, int Age = 0, float CGPA = 0) : Person(fName, lName, Age)
    {
        cgpa = CGPA;

        cout << "\nStudent() Called\n";
    }

    ~Student()
    {
        cout << "\n~Student() Called\n";
    }

    void PrintStudent()
    {
        cout << endl << GetFirstName() << " " << GetLastName() << " is " << age << " years old, his cgpa is " << cgpa << endl;
    }

    float GetCGPA()
    {
        return cgpa;
    }
};

class Faculty : public Person
{
private:
    int course_count;
    char* telephone_extension_number;

public:
    Faculty(const char* fName = nullptr, const char* lName = nullptr, int Age = 0, int count = 0, const char* tel_number = nullptr) : Person(fName, lName, Age)
    {
        course_count = count;

        if (tel_number != nullptr)
        {
            telephone_extension_number = new char[StringLength(tel_number) + 1];
            StringCopy(telephone_extension_number, tel_number);
        }
        else
            telephone_extension_number = nullptr;

        cout << "\nFaculty() Called\n";
    }
    ~Faculty()
    {
        delete[] telephone_extension_number;

        cout << "\n~Faculty() Called\n";
    }

    void PrintFaculty()
    {
        cout << "\nFaculty Member Name: " << GetFirstName() << " " << GetLastName() << ", Age: " << age << ", Number of Courses: " << course_count << ", Ext. " << telephone_extension_number << endl;
    }
};

class Undergraduate : public Student
{
private:
    char* fyp_name;

public:
    Undergraduate(const char* fName = nullptr, const char* lName = nullptr, int Age = 0, float CGPA = 0, const char* str = nullptr) : Student(fName, lName, Age, CGPA)
    {
        if (str != nullptr)
        {
            fyp_name = new char[StringLength(str) + 1];
            StringCopy(fyp_name, str);
        }
        else
            fyp_name = nullptr;

        cout << "\nUndergraduate() Called\n";
    }

    ~Undergraduate()
    {
        delete[] fyp_name;

        cout << "\n~Undergraduate() Called\n";
    }

    void PrintUndergraduate()
    {
        cout << endl << GetFirstName() << " " << GetLastName() << " is an undergraduate student, his cgpa is " << GetCGPA() << " and his final year project is " << fyp_name << endl;
    }
};

class Graduate : public Student
{
private:
    char* thesis_topic;

public:
    Graduate(const char* fName = nullptr, const char* lName = nullptr, int Age = 0, float CGPA = 0, const char* topic = nullptr) : Student(fName, lName, Age, CGPA)
    {
        if (topic != nullptr)
        {
            thesis_topic = new char[StringLength(topic) + 1];
            StringCopy(thesis_topic, topic);
        }
        else
            thesis_topic = nullptr;

        cout << "\nGraduate() Called\n";
    }

    ~Graduate()
    {
        delete[] thesis_topic;
        
        cout << "\n~Graduate() Called\n";
    }

    void PrintGraduate()
    {
        cout << endl << GetFirstName() << " " << GetLastName() << " is a graduate student, his cgpa is " << GetCGPA() << " and his thesis topic is " << thesis_topic << endl;
    }
};

int main()
{   
    // Student s("Ted", "Thomson", 22, 3.91);
    // Faculty f("Richard", "Karp", 45, 2, "420");

    // s.PrintStudent();
    // f.PrintFaculty();

    Undergraduate u("Ted", "Thompson", 22, 3.91, "The Event Locator");
    Graduate g("Arnorld", "Gates", 25, 3.01, "Distributed Algorithms");

    u.PrintUndergraduate();
    g.PrintGraduate();

    u.PrintStudent();

    return 0;
}
