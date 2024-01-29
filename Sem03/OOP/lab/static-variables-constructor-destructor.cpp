#include <iostream>
using namespace std;

class ABC {
    int a;
    public:
    static int count1, count2;
    ABC()
    {
        cout<<"oject created\n";
        input();
        count1++;
    }
    ~ABC()
    {
        cout<<"object destroyed for a = "<<a<<endl;
        count2++;
    }
    void input()
    {
        cout<<"Enter a: ";
        cin>>a;
    }
};

int ABC::count1, ABC::count2;

void fun()
{
    ABC obj1;
}

int main()
{
    ABC obj2, obj3, obj4;
    fun();
    // cout<<"Number of ABC objects "<<obj1.count<<endl;
    cout<<"Number of ABC objects created "<<ABC::count1<<endl;
    cout<<"Number of ABC objects deleted "<<ABC::count2<<endl;
    return 0;
}   


void func3()
{
    cout<<"This is it";
}