#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream fout("sample.txt");
    fout << "This is it" << endl;
    fout.close();
ddd
    ifstream fin("sample.txt");
    // fin.open("sample.txt");
    string line;

    while (getline(fin, line))
    {
        cout << line << endl;
    }

    

    return 0;
}