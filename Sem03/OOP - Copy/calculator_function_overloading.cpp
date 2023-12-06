#include<iostream>
using namespace std;

class calculator {
    public:
    float calculate(float num1, float num2) {
        cout<<"(Multiplying) ";
        return num1*num2;
    }
    int calculate(int num1, int num2) {
        cout<<"(Adding) ";
        return num1+num2;
    }
    int calculate(float num1, int num2) {
        cout<<"(dividing) ";
        return num1/num2;
    }
};

int main() {
    calculator c;
    float f1, f2;
    int i1, i2;
    cout<<"Enter f1: ";
    cin>>f1;
    cout<<"Enter f2: ";
    cin>>f2;
    cout<<"Operation performed on float: "<<c.calculate(f1, f2)<<endl;

    cout<<"Enter i1: ";
    cin>>i1;
    cout<<"Enter i2: ";
    cin>>i2;
    cout<<"Operation performed on int: "<<c.calculate(i1, i2)<<endl;

    cout<<"Operation performed f1 / i2: "<<c.calculate(f1, i2)<<endl;
    return 0;
}