#include <iostream>
using namespace std;
class Base
{
public:
    virtual void fun()
    {
        cout << "Base" << endl;
    }
};
class Derived : public Base
{
public:
    virtual void fun()
    {
        cout << "Derived" << endl;
    }
};
int main()
{
    Derived d1;

    // d1.fun(); // which binding work here? static binding or dynamic binding

    // Derived d1;
    Base *bPtr = &d1;

    bPtr->fun(); // dynamic binding
    
    // Base &bRef = d1;
    // bRef.fun();  //dynamic binding

    // d1.fun();   //static binding

    return 0;
}