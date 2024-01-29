// This is a program for friend function

#include <iostream>
using namespace std;

class ABC {
    private:
    int a, b, c;
    public:
    void input()
    {
        cout<<"Enter a: ";
        cin>>a;
        cout<<"Enter b: ";
        cin>>b;
        cout<<"Enter c: ";
        cin>>c;
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
        a = x; b = y; c = z;
    }
    friend int main();
    friend int fun();
};
int fun() {
    ABC obj;
    obj.input();
    cout<<obj.a<<endl;
    cout<<obj.b<<endl;
    cout<<obj.c<<endl;
    return 0;
}
int main() {
    fun();
    return 0;
}

