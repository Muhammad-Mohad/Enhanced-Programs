#include <iostream>
using namespace std;

class Vehicle
{
    private:
        int speed;
        int capacity;

    public:
        Vehicle()
        {
            cout << "Vehicle() Called\n";
        }
        ~Vehicle()
        {
            cout << "~Vehicle() Called\n";
        }
};

class Car : public Vehicle
{
    private:
        int cost;

    public:
        Car()
        {
            cout << "Car() Called\n";
        }
        ~Car()
        {
            cout << "~Car() Called\n";
        }
};

class Boat : public Vehicle
{
    private:
        int price;

    public:
        Boat()
        {
            cout << "Boat() Called\n";
        }
        ~Boat()
        {
            cout << "~Boat() Called\n";
        }
};

class AmphibiousCar : public Car , public Boat
{
    private:
        int what;

    public:
        AmphibiousCar()
        {
            cout << "AmphibiousCar() Called\n";
        }
        ~AmphibiousCar()
        {
            cout << "~AmphibiousCar() Called()\n";
        }
};

int main()
{
    // Vehicle v1;
    // Car c1;
    // Boat b1;
    AmphibiousCar a1;
}

