#include <iostream>
using namespace std;

class Date
{
    private:
        // Members
        int Day;
        int Month;
        int Year;

    public:
        // Constructors
        Date();
        Date(int, int, int);

        // Destructor
        ~Date();

        // Functions
        void Print();
        void Input();
        int Compare(Date);
        Date IncrementMonth();

        // Setters
        void SetDay(int);
        void SetMonth(int);
        void SetYear(int);

        // Getters
        int GetDay();
        int GetMonth();
        int GetYear();
};

Date::Date()
{
    cout << "\nDefault Constructor Called\n";

    Day = 1;
    Month = 1;
    Year = 1926;
}

void Date::Print()
{
    cout << Day << "/" << Month << "/" << Year << endl;
}

Date::Date(int dd, int mm, int yyyy)
{
    cout << "\nOverloaded Function Called\n";

    Day = dd;
    Month = mm;
    Year = yyyy;
}

void Date::Input()
{
    cout << "\nEnter the Day: ";
    cin >> Day;

    cout << "Enter the Month: ";
    cin >> Month;

    cout << "Enter the Year: ";
    cin >> Year;
}

Date::~Date()
{
    cout << "\nDestructor Called\n";
}

void Date::SetDay(int dd)
{
    Day = dd;
}

void Date::SetMonth(int mm)
{
    Month = mm;
}

void Date::SetYear(int yyyy)
{
    Year = yyyy;
}

int Date::GetDay()
{
    return Day;
}

int Date::GetMonth()
{
    return Month;
}

int Date::GetYear()
{
    return Year;
}

int Date::Compare(Date date)
{
    if(Day > date.Day && Month > date.Month && Year > date.Year)
        return 1;

    else if(Day < date.Day && Month < date.Month && Year < date.Year)
        return -1;

    else
        return 0;
}

Date Date::IncrementMonth()
{
    return Date(Day, Month + 1, Year);
}