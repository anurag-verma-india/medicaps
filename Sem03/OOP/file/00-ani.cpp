
#include <iostream>
#include <math.h>
using namespace std;
void area(int x, int y);
void area(float s);
void area(float m, float n);
int main()
{
    cout << "\n Triangle Area finder\n\n";
    cout << "1. Area of Right Angled Triangle\n";
    cout << "2. Area of Equilateral Triangle\n";
    cout << "3. Area of Isoceles Triangle\n";
    cout << "4. Exit";
    cout << "\n Enter your choice:";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        int b_right, h_right;
        cout << "\n Enter Base and Height:";
        cin >> b_right >> h_right;
        area(b_right, h_right);
        break;
    case 2:
        float side;
        cout << "\n Enter the Length of side:";
        cin >> side;
        area(side);
        break;
    case 3:
        float a, b;
        cout << "\n Enter length of similar sides:";
        cin >> a;
        cout << "\n Enter the lenth of third side:";
        cin >> b;
        area(a, b);
        break;
    case 4:
        break;
    default:
        cout << "\n Invalid Option...";
    }
    return 0;
}
void area(int x, int y)
{
    float result_right;
    result_right = x * y / 2;
    cout << "\nArea of Right Angle Triangle=" << result_right;
}
void area(float s)
{
    float result_equi;
    result_equi = ((s * s) * sqrt(3)) / 4;
    cout << "\nArea of Equilateral Triangle=" << result_equi;
}
void area(float m, float n)
{
    float result_iso;
    result_iso = (n / 2) * sqrt((m * m) - (n * n) / 4);
    cout << "\nArea of Isoceles Triangle=" << result_iso;
}
