#include <iostream>
using namespace std;

class B;
class B {
    int b;
    public:
    void input2()
    {
        cout<<"Enter the value of b: ";
        cin>>b;
    }
    void display2()
    {
        cout<<"value of objB.b: "<<b<<endl;
    }
};
class A
{
    int a;
    public:
    void input1()
    {
        cin>>a;
    }
    void display1(B objB)
    {
        objB.display2();
        cout<<"\nEnter new value of objB.b in scope of ObjA\n";
        objB.input2();
        objB.display2();
        cout<<"Exiting display1 function\n\n";
    }
};



int main()
{
    A objA;
    B objB;
    objB.input2();
    objA.display1(objB);
    objB.display2();
    return 0;
}