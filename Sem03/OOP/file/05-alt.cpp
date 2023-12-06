#include <iostream>
using namespace std;
class Number
{
private:
    int value;

public:
    Number(int val) : value(val) {}
    Number operator-()
    {
        return Number(-value);
    }
    Number operator++()
    {
        ++value;
        return *this;
    }
    Number operator--()
    {
        --value;
        return *this;
    }
    bool operator!()
    {
        return (value == 0);
    }
    void display()
    {
        cout << "Current Value: " << value << endl;
    }
};
int main()
{

    Number num(5);
    Number negatedNum = -num;
    cout << "Unary '-' operator\n";
    negatedNum.display();
    Number incrementedNum = ++num;
    cout << "Unary '++' operator\n";
    incrementedNum.display();
    Number decrementedNum = --num;
    cout << "Unary '--' operator\n";
    decrementedNum.display();
    bool isZero = !num;
    cout << "Unary '!' operator: " << (isZero ? "true" : "false") << endl;
    return 0;
}
