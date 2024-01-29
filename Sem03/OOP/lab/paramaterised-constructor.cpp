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
};

int main() {
    ABC obj1, obj2(2,3,5);
    cout<<"Obj1: "<<endl;
    obj1.display();
    cout<<endl;
    cout<<"Obj2: "<<endl;
    obj2.display();
}
