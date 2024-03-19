#include <iostream>
using namespace std;
int main()
{
    int i, j, k, n;
    float time_quantum, throughput, average_waiting_time, avtat, sum1 = 0, sum2 = 0, temp = 0;
    cout << "\n enter the number of processes";
    cin >> n;
    float p[n], job[n], bt[n], at[n], ct[n], tat[n], wt[n], rt[n];
    for (i = 0; i < n; i++)
    {
        job[i] = i + 1;
    }
    cout << "\n enter the burst time of each processes";
    for (i = 0; i < n; i++)
    {
        cin >> bt[i];
    }
    cout << "\n enter the time quantum";
    cin >> time_quantum;
    for (i = 0; i < n; i++)
    {
        rt[i] = bt[i];
    }
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (rt[i] != 0)
            {
                if (rt[i] > time_quantum)
                {
                    temp = temp + time_quantum;
                    rt[i] -= time_quantum;
                }
                else
                {
                    temp = temp + rt[i];
                    rt[i] -= rt[i];
                    ct[i] = temp;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
    }
    cout << "\njob bt ct tat wt \n";
    for (i = 0; i < n; i++)
    {
        cout << job[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }
    for (i = 0; i < n; i++)
    {
        sum1 += tat[i];
        sum2 += wt[i];
    }
    avtat = sum1 / n;
    average_waiting_time = sum2 / n;
    throughput = float(n / ct[n - 1]);
    cout << "\naverage turn around time is : " << avtat << endl;
    cout << "\naverage waiting time is : " << average_waiting_time << endl;
    cout << "\n throughput" << throughput;
    return 0;
}