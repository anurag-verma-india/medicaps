// Write a program to print table of a number given of a user
#include <iostream>
using namespace std;

void table(int);

int main()
{
	int num;

	cout << "Please enter a number: ";
	cin >> num;
	table(num);



	return 0;
}

void table(int num) {
	cout << "\nThe table of " << num << " is: ";
    for (int i = 1; i<= 10; i++ ) {
        cout << num * i << " ";
    }
    
}