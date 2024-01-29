#include <iostream>
using namespace std;

class Complex
{
public:
    int real, imag;
    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }
    void print()
    {
        cout << real << " + " << imag << "i";
    }
    Complex operator+(Complex const &obj)
    {
        Complex result(0, 0);
        result.real = real + obj.real;
        result.imag = imag + obj.imag;
        return result;
    }
};

int main()
{
    Complex a(1, 1), b(2, 2);
    Complex c = a+b;
    c.print();
}