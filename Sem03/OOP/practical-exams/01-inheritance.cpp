#include <iostream>
#include <string.h>
using namespace std;

class Animal {
    string name;
    public:
    void setName(string n) {
        name = n;
    }
    void getName() {
        cout<<"Name: " << name<<endl;
    }
};

class Dog: public Animal {
    int no_of_legs;
    public:
    void setLegs(int i) {
        no_of_legs = i;
    }
    void getLegs() {
        cout<<"This dog has " << no_of_legs << " legs"<< endl;
    }
};

int main() {
    Dog d1;
    d1.setName("Pluto");
    d1.setLegs(4);
    d1.getName();
    d1.getLegs();
    return 0;
}