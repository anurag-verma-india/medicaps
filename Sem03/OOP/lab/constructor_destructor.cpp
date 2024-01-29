#include <iostream>
using namespace std;

class Student {
    int roll;
    public: Student() {
        cout<<"Object created"<<endl;
        cout<<"You can give initial value to roll no: ";
        cin>>roll;
    }
    public: void input() {
        cout<<"Enter the new value for roll no: ";
        cin>>roll;
    }
    public: void display() {
        cout<<"Roll Number: " << roll << endl;
    }
    ~Student() {
        cout<<"The object has been destroyed\n";
    }
};

int main() {
    Student s1, s2;
    s1.display();
    s2.display();    
    return 0;
}