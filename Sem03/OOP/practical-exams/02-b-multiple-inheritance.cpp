#include <iostream>
using namespace std;

class Vehicle {
    public:
        void vehicle() {
            cout << "I am a vehicle" << endl;
        }
};

class FourWheeler {
    public:
        void fourWheeler() {
            cout << "I have four wheels" << endl;
        }
};

class Car : public Vehicle, public FourWheeler {
    public:
        void car() {
            cout << "I am a car" << endl;
        }
};

int main() {
    Car obj;
    obj.car();
    obj.fourWheeler();
    obj.vehicle();
    return 0;
}
