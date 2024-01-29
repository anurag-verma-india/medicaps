#include <iostream>
#include <fstream>
#include <string.h>
// #include <process.h>
// #include <cstring>
using namespace std;

int main() {
    // char arr[999];
    // char age[10];
    string str;
    ofstream writeMode;
    writeMode.open("name.txt");
    cout << "Enter your name: ";
    cin >> str;
    writeMode << "Name: "<< str << endl;
    cout << "Enter you age: ";

    writeMode.close();
    cout<<"******** Reading from file ********"<<endl;


    ifstream readMode;
    readMode.open("name.txt");
    readMode >> str;
    cout << str << endl;
    readMode >> str;
    cout << str << endl;
    return 0;
}