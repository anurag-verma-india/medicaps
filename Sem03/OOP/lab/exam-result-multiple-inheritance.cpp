#include <iostream>
using namespace std;

class exam {
    protected:
    int m[4];
    public:
    void input() {
        for(int i = 0; i<4; i++){
            cin>>m[i];
        }
    }
    void display() {
        for(int i = 0; i<4; i++){
            cout<<"m"<<i<<m[i]<<endl;
        }
    }
};

class student {
    public:
    string name;
    int roll_no;
    void get() {
        cout<<"Name: "<<name;
        cout<<"Roll number: "<<roll_no;
    }
    void set() {
        cout<<"Enter student's name: ";
        cin>>name;
        cout<<"Enter student's roll number: ";
        cin>>roll_no;
    }
};

class rerult: public exam, public student {
    int semester;
    float percent;
    float calculate() {
        for(int i = 0; i<4; i++){
            percent += m[i];
        }
        percent *= (4/100);
    }
};