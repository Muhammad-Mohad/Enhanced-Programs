#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    Date date1, independenceDay(14, 8, 1947), xmasDay, temp, updated_date1;

    cout << "\nDate 1: ";
    date1.Print();

    cout << "\nIndependence Day: ";
    independenceDay.Print();

    cout << "\nEnter your Date of Birth: \n";
    date1.Input();

    cout << "\nDate of Birth: ";
    date1.Print();

    cout << "\nBefore Setters:\nxmasDay: ";
    xmasDay.Print();

    xmasDay.SetDay(25);
    xmasDay.SetMonth(12);
    xmasDay.SetYear(2018);

    cout << "\nAfter Setters:\nxmasDat: ";
    xmasDay.Print();

    int dd = xmasDay.GetDay();
    int mm = xmasDay.GetMonth();
    int yyyy = xmasDay.GetYear();
    cout << "\nPrinting xmasDay using Getters: " << dd << "/" << mm << "/" << yyyy;

    cout << "\n\ntemp: ";
    temp = xmasDay;
    temp.Print();

    int compare = xmasDay.Compare(independenceDay);
    cout << "\nValue after Comapring xmasDay and independenceDay: " << compare << endl;

    cout << "\nIncrement in Month: \n";
    updated_date1 = date1.IncrementMonth();
    cout << "\nDate1: ";
    date1.Print();
    cout << "\nupdated_Date1: ";
    updated_date1.Print();
    
    return 0;
}