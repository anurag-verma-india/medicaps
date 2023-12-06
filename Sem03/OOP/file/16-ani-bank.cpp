#include <iostream>
using namespace std;
class Bank
{
private:
    char account_holder[50];
    int accnum;
    int balance;
    int dep_amount;
    int with_amount;

public:
    void getdata();
    void putdata();
    void deposit();
    void withdraw();
};
void Bank::getdata()
{
    cout << "Enter the account holders name: ";
    cin >> account_holder;
    cout << "Enter the account number: ";
    cin >> accnum;
    cout << "Enter the balance in your account: ";
    cin >> balance;
}
void Bank::putdata()
{
    cout << "The account holders name is: " << account_holder << endl;
    cout << "The account number is: " << accnum << endl;
    cout << "The balance in your account is: " << balance << endl;
    cout << endl;
}
void Bank::deposit()
{
    cout << "Enter the amount to be deposited: ";
    cin >> dep_amount;
    balance = balance + dep_amount;
    cout << "Your current balance is: " << balance << endl;
}
void Bank::withdraw()
{
    cout << "Enter the amount to be withdrawn: ";
    cin >> with_amount;
    balance = balance - with_amount;
    cout << "Your current balance is: " << balance << endl;
}
int main()
{
    Bank ram[5];
    int ch, a, n, acc;
    cout << "How many account holders do you want to add: ";
    cin >> n;
    do
    {
        cout << "\nEnter 1 to insert data" << endl;
        cout << "Enter 2 to display data" << endl;
        cout << "Enter 3 to deposit amount" << endl;
        cout << "Enter 4 to withdraw amount" << endl;
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            for (int i = 0; i < n; i++)
                ram[i].getdata();
            break;
        case 2:
            for (int i = 0; i < n; i++)
                ram[i].putdata();
            break;
        case 3:
            cout << "Enter the account you want to deposit money into: ";
            cin >> acc;
            for (int i = 0; i < n; i++)
                ram[acc].deposit();
            break;
        case 4:
            for (int i = 0; i < n; i++)
                ram[i].withdraw();
            break;
        }
        cout << "\nEnter 6 to Continue (any other character to end program)" << endl;
        cin >> a;
    } while (a == 6);
    return 0;
}
