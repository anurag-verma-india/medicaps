#include<iostream>
using namespace std;

class Complex {
public:
    int real, imag;
    Complex(int r = 0, int i =0)  {real = r;   imag = i;}

    void show() {
        cout << "(" << real << ")+(" << imag << ")i" << endl;
    }

    Complex operator- () {
        Complex comp;
        comp.real= -real;
        comp.imag = -imag;
        return comp;
    }
};

int main()
{
    Complex c1(2 , 5);
    c1.show();
    Complex neg_c1 = -c1;
    neg_c1.show();
}