#include <iostream>
using namespace std;

class Address {
    int house_number;
    char area[15];
    char city[15];
    int pin;
    public:
    void enter_address() {
        
        cout<<"Enter the house number: ";
        cin>>house_number;
        cout<<"Enter the area: ";
        cin>>area;
        cout<<"Enter the city: ";
        cin>>city;
        cout<<"Enter the pin: ";
        cin>>pin;
    }
    void display_address() {
        cout<<"The address is: ";
        cout<<"House Number "<<house_number<<", "<<area<<", "<<city<<", "<<pin<<endl;
    }
    Address() {
    }
};

class Person {
    char name[30];
    long int mob;
    Address add;
    public:

    // for aggregation 
    // void enter_detail(Address &add1) {
    void enter_detail(Address add1) {
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter mobile number: ";
        cin>>mob;
        add1.display_address();
        cout<<"\nIn person class "<<endl;
        add1.enter_address();
    }
};

int main() {
    Address add1;
    add1.enter_address();
    Person p1;
    p1.enter_detail(add1);
    cout<<"In main function\nAddress is: ";
    add1.display_address();
}
