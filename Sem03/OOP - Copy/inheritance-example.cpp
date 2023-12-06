#include <iostream>
using namespace std;

class A {
    private: int a;
    protected: int b;
    public:
    int c;
    void input() {
        cout<<"Enter a: ";
        cin >>a;
        cout<<"Enter b: ";
        cin>>b;
        cout<<"Enter c: ";
        cin>>c;
    }
    void display() {
        cout<<"a: "<<a<<endl;
        cout<<"b: "<<b<<endl;
        cout<<"c: "<<c<<endl;
    }
};

class B: public A {
    public: int d;
    void set() {
        input();
        cout<<"Enter d: ";
        cin>>d;
    }
    void output() {
        display();
        cout<<"d: "<<d;
    }
};

int main() {
    A a1;
    B b1;
    b1.set();
    b1.output();
    return 0;
}
