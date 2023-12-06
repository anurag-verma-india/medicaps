// Write a program to print table of a number given of a user
#include <iostream>
using namespace std;

int main()
{
	int num;

	cout << "Please enter a number: ";
	cin >> num;
	cout << "\nThe table of " << num << " is: ";
    for (int i = 1; i<= 10; i++ ) {
        cout << num * i << " ";
    }

	return 0;
}
