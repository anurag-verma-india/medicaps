#include <iostream>
using namespace std;

template <typename T>
T myMax(T a, T b) {
    if (a > b) return a;
    else return b;
}

int main() {
    cout<<myMax<int>(0, 100)<<endl;
    return 0;
}
