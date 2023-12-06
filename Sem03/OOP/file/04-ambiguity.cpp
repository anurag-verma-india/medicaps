#include<iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "This is animal sound." << endl;
    }
};
class Dog : public Animal {
public:
    void sound() {
        cout << "Bark!" << endl;
    }
};
class Cat : public Animal {
public:
    void sound() {
        cout << "Meow!" << endl;
    }
};

class DogCat : public Dog, public Cat {
public:
    void sound() {
        Dog::sound();
        Cat::sound();
    }
};

int main() {
    Dog d1;
    cout << "Sound of dog: ";
    d1.sound();
    Cat c1;
    cout << "Sound of cat: ";
    c1.sound();
    DogCat dc;
    cout << "Sound of cat and dog together: " << endl;
    dc.sound();
    return 0;
}
