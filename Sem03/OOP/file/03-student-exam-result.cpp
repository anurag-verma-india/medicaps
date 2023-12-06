#include <iostream>
using namespace std;

class student {
    public:
        int roll_no;
        string name;
};

class exam : public student {
    public:
        int marks[5];
};

class result : public exam {
    public:
        int total;
        float avg;
        void calculate() {
            total = 0;
            for (int i = 0; i < 5; i++) {
                total += marks[i];
            }
            avg = total / 5;
        }
};

int main() {
    result r;
    cout << "Enter name of student: ";
    cin >> r.name;
    cout << "Enter roll number: ";
    cin >> r.roll_no;
    for (int i = 0; i < 5; i++) {
        cout << "Enter marks of subject number " << i+1 << ": ";
        cin >> r.marks[i];
    }
    r.calculate();

    cout << "\nFinal Result of student" << endl;
    cout << "Roll No.: " << r.roll_no << endl;
    cout << "Name: " << r.name << endl;
    cout << "Marks: ";
    for (int i = 0; i < 5; i++) {
        cout << r.marks[i] << " ";
    }
    cout << "\nFinal percentage: " << r.avg << endl;
    return 0;
}