#include <iostream>
using namespace std;

void StrCopy(char* dest, const char* src, int count)
{
    int i;
    for (i = 0; i < count && src[i] != '\0'; i++)
        dest[i] = src[i];

    for (; i < count; i++)
        dest[i] = '\0';
}

int StrCompare(const char* str1, const char* str2) 
{
    while (*str1 && *str2 && *str1 == *str2) 
    {
        str1++;
        str2++;
    }
    
    if (*str1 == *str2) 
        return 0; 
    else if (*str1 < *str2) 
        return -1; 
    else 
        return 1; 
}

class Student
{
    private:
        char rollNo[8];
        char name[50];
        float cgpa;

    public:
        Student(const char* val1 = "", const char* val2 = "", float val3 = 0)
        {
            StrCopy(rollNo, val1, 8);
            StrCopy(name, val2, 50);
            cgpa = val3;
        } 

        

        void Print(bool check)
        {
            if (check == true)
                cout << name << " (" << rollNo << ")";
            else
                cout << name;
        }

        const char* GetName()
        {
            return name;
        }

        float GetCgpa()
        {
            return cgpa;
        }
};

class Society
{
    private:
        char name[50];
        Student* president;
        Student* members[5];

    public:
        Society(const char* val = "")
        {
            StrCopy(name, val, 50);

            president = nullptr;

            for(int i = 0; i < 5; i++)
                members[i] = nullptr;
        }

        void PrintInfo()
        {
            cout << "Society Name:\t" << name << endl;
            
            if(president == nullptr)
                cout << "President:\tNot Available" << endl;
            else
            {
                cout << "President:\t";
                president->Print(true);
                cout << endl;
            }
            
            for(int i = 0; i < 5; i++)
            {
                if(members[i] != nullptr)
                {
                    cout << "Member " << i + 1 << ":\t";
                    members[i]->Print(true);
                    cout << endl;
                }
                else
                    cout << "Member " << i + 1 << ":\tNot Available" << endl;
            }
        }

        void AppointPresident(Student& student)
        {
            if (president == nullptr) 
            {
                if (student.GetCgpa() >= 3.00) 
                {
                    president = &student;
                    cout << president->GetName() << " has been appointed as President." << endl;
                } 
                else 
                    cout << student.GetName() << " cannot be appointed as President. CGPA criteria not met." << endl;
            }

            else 
                cout << student.GetName() << " cannot be appointed as President. President position is not vacant." << endl;
        }

        void AddMember(Student* student)
        {
            if (president != student)
            {
                bool positionVacant = false;

                for (int i = 0; i < 5; i++)
                {
                    if (members[i] == nullptr)
                    {
                        positionVacant = true;
                        break;
                    }
                }
                if (positionVacant)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        if (members[i] == student)
                        {
                            student->Print(false);
                            cout << " already exists in Members list." << endl;
                            return;
                        }
                    }

                    for (int i = 0; i < 5; i++)
                    {
                        if (members[i] == nullptr)
                        {
                            members[i] = student;
                            student->Print(false);
                            cout << " has been added to members list successfully." << endl;
                            return;
                        }
                    }
                }
                else
                {
                    student->Print(false);
                    cout << " cannot be added to members list. Member position is not vacant." << endl;
                }
            }
            else
            {
                cout << "President cannot be added in Members list." << endl;
            }
        }

        void SuspendMember(const char* memberName)
        {
            bool found = false;

            for (int i = 0; i < 5; i++) 
            {
                if (members[i] != nullptr && StrCompare(members[i]->GetName(), memberName) == 0) 
                {
                    found = true;
                
                    members[i] = nullptr;
                    cout << memberName << " has been suspended from " << name << " society." << endl;
                    break;
                }
            }
            if (!found) 
            {
                cout << memberName << " not found in the Members list." << endl;
            }
        }
};



int main()
{
    Student s1("12L1111", "Hashim Amla", 3.99);
	Student s2("13L1121", "Virat Kohli", 3.45);
	Student s3("13L1126", "Quinton de Kock", 2.98);
	Student s4("14L1361", "Joe Root", 2.99);
	Student s5("14L1124", "Martin Guptil", 3.09);
	Student s6("15L1314", "Rohit Sharma", 3.19);

    Society sports("Sports");

    cout << "\n\n";

    sports.PrintInfo();

    cout << "\n\n";

    sports.AppointPresident(s3);
    sports.AppointPresident(s1);
    sports.AppointPresident(s2);

    cout << "\n\n";

    Student s7("15L1334", "Robert Elen", 2.19);

	sports.AddMember(&s3);
	sports.AddMember(&s2);
    sports.AddMember(&s3);
	sports.AddMember(&s1);
	sports.AddMember(&s4);
	sports.AddMember(&s5);
	sports.AddMember(&s6);
	sports.AddMember(&s7);

    cout << "\n\n";

    sports.PrintInfo();

    cout << "\n\n";

    sports.SuspendMember("abc");
	sports.SuspendMember("Martin Guptil");

    cout << "\n\n";

    sports.PrintInfo();

    cout << "\n\n";

    Society ieee("IEEE");

	ieee.AppointPresident(s5);

    cout << "\n\n";

	ieee.PrintInfo();

    return 0;
}