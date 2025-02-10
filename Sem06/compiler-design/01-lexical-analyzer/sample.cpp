#include <string.h>

#include <iostream>

using namespace std;
void file_as_stdin(const string& filePath) {
    if (!freopen(filePath.c_str(), "r", stdin)) {
        cerr << "There was a problem opening the input file: " << filePath;
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 1) {
        cerr << "Please enter the path to the c file" << "\n";
    }
    file_as_stdin(argv[1]);
    string a;
    cin >> a;

    cout << a;
    printf("\n");

    return 0;
}