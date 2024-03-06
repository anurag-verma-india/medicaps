#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void bubbleSortMulti(int arr[][5], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j][0] > arr[j + 1][0])
                swap(arr[j], arr[j + 1]);
}

int main()
{
    int n = 4;
    int arr_multi[n][5] = {
        {7, 7, 7, 7, 7},
        {4, 4, 4, 4, 4},
        {1, 1, 1, 1, 1},
        {3, 3, 3, 3, 3}};

    bubbleSortMulti(arr_multi, n);

    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            cout << arr_multi[i][k] << "\t";
        }
        cout << endl;
    }

    // int arr[5]={5,3,2,6,8};

    // bubbleSort(arr, 5);

    // cout<<endl;
    // for(int i=0;i<5;i++) cout<<arr[i]<<"\t";
    // cout<<endl;

    return 0;
}