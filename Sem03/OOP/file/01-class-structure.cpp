#include <iostream>
using namespace std;

class Animal
{
    string name;
    string type;
    public:
    Animal(string animal_type, string animal_name)
    {
        name = animal_name;
        type = animal_type;
    }
    void print_name()
    {
        cout<<"The name of this "<<type<<" is "<<name<<endl;
    }
};

int main()
{
    Animal h1("Horse", "Jim");
    h1.print_name();
    return 0;
}