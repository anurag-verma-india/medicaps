#include <iostream>
using namespace std;
class Animal
{
public:
    // turn the following virtual modifier on/off to see what happens
    virtual 
    string Says() { return "?"; }
};

class Entity
{
public:
    string Says() { return "!"; }
};

// class Dog: public Animal
class Dog : public Animal, public Entity
{
public:
    string Says() { return "Woof"; }
};

int main()
{
    Dog *d = new Dog();
    Animal *a = d; // refer to Dog instance with Animal pointer

    cout << a->Says(); // Woof or ?, depends on virtual
    cout << d->Says(); // always Woof
    return 0;
}