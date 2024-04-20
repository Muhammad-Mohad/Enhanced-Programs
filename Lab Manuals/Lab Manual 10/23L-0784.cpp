#include <iostream>
using namespace std;

class Animal
{
    public:
        virtual const char* speak()
        {
            return "Speak() Called";
        }
        virtual ~Animal()
        {
            cout << "~Animal() Called.\n";
        }
};

class Dog : public Animal
{
    public:
        const char* speak()
        {
            return "Woof!";
        }
        ~Dog()
        {
            cout << "~Dog() Called.\n";
        }
};

class Cat : public Animal
{
    public:
        const char* speak()
        {
            return "Mew!";
        }
        ~Cat()
        {
            cout << "~Cat() Called.\n";
        }
};

class Sheep : public Animal
{
    public:
        const char* speak()
        {
            return "Bleat!";
        }
        ~Sheep()
        {
            cout << "~Sheep() Called.\n";
        }
};

class Cow : public Animal
{
    public:
        const char* speak()
        {
            return "Moo!";
        }
        ~Cow()
        {
            cout << "~Cow() Called.\n";
        }
};

class Horse : public Animal
{
    public:
        const char* speak()
        {
            return "Neigh!";
        }
        ~Horse()
        {
            cout << "~Horse() Called.\n";
        }
};



int main()
{
    // Animal objAnimal;
    // Dog objDog;
    // Animal* ptrAnimal = &objAnimal;
    // Dog* ptrDog = &objDog;

    // cout << objAnimal.speak() << endl;
    // cout << objDog.speak() << endl;
    // cout << ptrAnimal->speak() << endl;
    // cout << ptrDog->speak() << endl;

    // Dog lassie;
    // Animal* myPet = &lassie;
    // cout << myPet->speak() << endl;

    // const int size = 2;
    // Animal* myPets[size];
    // Cat whiskers;
    // Dog mutley;

    // myPets[0] = &whiskers;
    // myPets[1] = &mutley;

    // for(int i = 0; i < size; i++)
    //     cout << myPets[i]->speak() << endl;

    const int size = 5;
    Animal* myPets[size];

    int i = 0;
    int input = 0;

    while(i < size)
    {
        cout << "Press '1' for a Dog , '2' for a Cat , '3' for a Sheep , '4' for a Cow and '5' for a Horse: ";

        cin >> input;

        if(input == 1)
        {
            myPets[i] = new Dog;
            cout << "Dog added at position " << i << endl << endl;
            i++;
        }
        else if(input == 2)
        {
            myPets[i] = new Cat;
            cout << "Cat added at position " << i << endl << endl;
            i++;
        }
        else if(input == 3)
        {
            myPets[i] = new Sheep;
            cout << "Sheep added at position " << i << endl << endl;
            i++;
        }
        else if(input == 4)
        {
            myPets[i] = new Cow;
            cout << "Cow added at position " << i << endl << endl;
            i++;
        }
        else if(input == 5)
        {
            myPets[i] = new Horse;
            cout << "Horse added at position " << i << endl << endl;
            i++;
        }
        else
            cout << "Invalid Input. Enter Again." << endl << endl;
    }

    for(int i = 0; i < size; i++)
        delete myPets[i];

    return 0;
}