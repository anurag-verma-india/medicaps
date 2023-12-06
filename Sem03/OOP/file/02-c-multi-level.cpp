#include <iostream>
using namespace std;

class Animal {
    public:
        void animal() {
            cout << "I am an animal" << endl;
        }
};

class Pet {
    public:
        void pet() {
            cout << "I am a pet" << endl;
        }
};

class Dog : public Animal, public Pet {
    public:
        void dog() {
            cout << "I am a dog" << endl;
        }
};

int main() {
    Dog obj;
    obj.dog();
    obj.pet();
    obj.animal();
    return 0;
}