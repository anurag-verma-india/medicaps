#include<iostream>
using namespace std;

class Engine {
    char type;
    public:
    Engine() {
        cout<<"Engine created"<<endl;
    }
    ~Engine() {
        cout<<"Engine destroyed"<<endl;
    }
};

class Car {
    Engine *e1;
    char company[10];
    public:
    void details() {
        cout<<"Enter car company: ";
        cin>>company;
    }
    Car() {
        e1 = new Engine();
        cout<<"Car created"<<endl;
    }
    ~Car() {
        delete(e1);
        cout<<"Car destroyed"<<endl;
    }
};

int main() {
    Car c1;
    return 0;
}