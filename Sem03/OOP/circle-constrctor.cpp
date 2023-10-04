#include <iostream>
using namespace std;

class circle {
    int radius;
    public:
    circle()
    {
        cout<<"New circle created" <<endl;
    }
    ~circle()
    {
        cout<<"One circle destroyed"<<endl;
    }
    void input()
    {
        cout<<"Enter radius: ";
        cin>>radius;
    }
};

int main()
{
    circle c1;
    c1.input();

    circle *c2 = new circle();
    c2 ->input();
    delete(c2);
    return 0;
}