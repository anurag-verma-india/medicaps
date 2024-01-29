// Count the total number of Apple, Mangoes, and also total number of fruits

#include <iostream>
using namespace std;

class Fruit {
    public:
    static int fruit_num;
    Fruit() {
        cout<<"This is a fruit\n";
        fruit_num++;
    }
};

class Mango: public Fruit {
    public:
    static int mango_num;
    Mango() {
        cout<<"This is a mango\n";
        mango_num++;
    }
};

class Apple: public Fruit {
    public:
    static int apple_num;
    Apple() {
        cout<<"This is an apple\n";
        apple_num++;
    }
};

int Apple::apple_num= 0;
int Mango::mango_num=0;
int Fruit::fruit_num=0;

int main() {
    Mango m1, m2;
    Apple a1, a2, a3;

    cout<<"Total number of Mangoes: "<<Mango::mango_num<<endl;
    cout<<"Total number of Apples: "<<Apple::apple_num<<endl;
    cout<<"Total number of fruits: "<<Fruit::fruit_num<<endl;

    return 0;
}