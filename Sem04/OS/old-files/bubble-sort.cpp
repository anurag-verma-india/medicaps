#include <iostream>
#include <iomanip>

using namespace std;

void sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

int main()
{
    int array[5] = {4, 3, 1, 2, 5};
    // for(int i=0;i<5;i++){
    //     cout<<"Element "<<i<<": ";
    //     cin>>array[i];
    // }
    sort(array, 5);
    cout << "\nSorted Array: \n";
    for (int i = 0; i < 5; i++)
    {
        cout << setw(5) << array[i];
    }
    cout << endl;
}