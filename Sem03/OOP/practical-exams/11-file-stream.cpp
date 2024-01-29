#include <iostream>
#include <fstream>
#include <cstring>
#include <process.h>
using namespace std;
int main()
{
    char arr[999];             // Used to store data
    ofstream writeMode;         // Created object of ofstream
    writeMode.open("name.dat"); // Opened the file in write mode
    cout << "******** Writing into file ********" << endl;
    cout << "Enter your name: ";
    cin.getline(arr, 999);    // Accepts string with spaces and after spaces eg ____ ____
    writeMode << arr << endl; // Putted data inside the file
    cout << "Enter your age: ";
    cin >> arr;
    cin.ignore();              // Wrote because number is accepted :P, may be
    writeMode << arr << endl; // Again putted data inside the file
    writeMode.close();         // Closed the write mode
    ifstream readMode;         // Created object of ifstream
    readMode.open("name.dat"); // Opened the file in read mode.
    cout << "******** Reading into file ********" << endl;
    readMode >> arr;
    cout << arr << endl; // Write the data to the screen
    readMode >> arr;     // again read the data from the file and display it
    cout << arr << endl;
    readMode.close(); // Closed the read mode
    // system("pause");
    return 0;
}   