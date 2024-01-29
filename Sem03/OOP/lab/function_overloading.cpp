#include <string>
#include <iostream>
using namespace std;

float area(int rad) 
{
    return (3.14 * rad * rad);
}

float area(float base, float height) 
{
    return 0.5*base*height;
}

float area(int length, int breadth) 
{
    return length * breadth;
}

int main()
{
    cout<<"Choose one of the following by entering a number\n1. Circle\n2. Triangle\n3. Rectangle";

    float base, height;
    cout<<"Enter the base and height: ";
    cin>>base>>height;
    cout<<area(base, height);
    return 0;
}
