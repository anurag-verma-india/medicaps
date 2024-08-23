#include <iostream>
using namespace std;

void bubbleSort(int bt[], int tat[], int wt[], int n, int what_to_sort)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {

        switch (what_to_sort)
        {
        case 0:
        {
            for (j = 0; j < n - i - 1; j++)
            {
                if (bt[j] < bt[j + 1])
                {
                    swap(bt[j], bt[j + 1]);
                    swap(tat[j], tat[j + 1]);
                    swap(wt[j], wt[j + 1]);
                }
            }
        }
        break;
        case 1:
        {
            for (j = 0; j < n - i - 1; j++)
            {
                if (tat[j] < tat[j + 1])
                {
                    swap(bt[j], bt[j + 1]);
                    swap(tat[j], tat[j + 1]);
                    swap(wt[j], wt[j + 1]);
                }
            }
        }
            break;
        case 2:
        {
            for (j = 0; j < n - i - 1; j++)
            {
                if (wt[j] < wt[j + 1])
                {
                    swap(bt[j], bt[j + 1]);
                    swap(tat[j], tat[j + 1]);
                    swap(wt[j], wt[j + 1]);
                }
            }
        }
            break;
        }
    }
}

int main()
{
    int bt[20], tat[20], wt[20], i, j, n, total, pos, temp;
    float avg_wt, avg_tat;

    cout << "\nEnter number of processes: ";
    cin >> n;

    cout << "\nEnter burst times of processes: \n";
    for (i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "]: ";
        cin >> bt[i];
    }

    bubbleSort(bt, tat, wt, n, 0);

    for(i=1;i<n;i++) {
        wt[i] = 0;
        for(j=0;j<i;j++) {
            wt[i]+=bt[j];
        }
    }

    cout << "\nPro.\tBT\tTAT\tWT\n";

    for (i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "]" << "\t" << bt[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    return 0;
}