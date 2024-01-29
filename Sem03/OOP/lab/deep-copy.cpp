#include <iostream>
using namespace std;

class ABC {
    private:
    int a, b, c;
    public:
    void input()
    {
    }
    void display()
    {
        cout<<"A: " << a <<endl<< "B: "<<b<<endl<<"C: " <<c<<endl;
    }
    ABC()
    {
        a=0;b=0;c=0;
    }
    ABC(int x, int y, int z)
    {
        cout<<"Parameterized constructor called"<<endl;
        a = x; b = y; c = z;
    }

    // Copy Constructor
    ABC(ABC &obj)
    {
        a = obj.a;
        b = obj.b;
        c= obj.c;
    }
};

int main() {
    ABC obj1(3, 1, 4);
    ABC obj2(obj1);
    obj2.display();
}
