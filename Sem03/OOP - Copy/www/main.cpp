#include <iostream>
using namespace std;

class BankAccount {
    private:
    string accNum, accHolderName;
    float balance;
    public:
    BankAccount(string name, string num, float intBalance) {
        accHolderName = name;
        accNum = num;
        intBalance = balance;
    }
    void printName() {
        cout<<accHolderName;
    }
};

int main() {
    BankAccount b("Peter", "1122", 1000);
    b.printName();
    return 0;
}