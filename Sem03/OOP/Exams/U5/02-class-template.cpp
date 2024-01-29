#include <iostream>
using namespace std;

template <typename T>
class Array
{
    T *ptr;
    int size;

public:
    Array(T arr[], int s)
    {
        ptr = new T[s];
        size = s;
        for (int i = 0; i < size; i++)
        {
            ptr[i] = arr[i];
        }
    }
    T print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << ptr[i] << " ";
        }
    }
};

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    Array<int> a(arr, 5);
    a.print();
    return 0;
}       