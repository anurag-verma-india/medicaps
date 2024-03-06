#include <iostream>
using namespace std;

// To find the waiting time for all processes
void findWT(int prcs[], int n,int bt[], int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;

    // calculating waiting time
    for (int i = 1; i < n; i++){
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

//  to calculate turn around time
void findTAT(int prcs[], int n,int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding  (burst time)bt[i] + wt[i](waiting time)
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

//To calculate average time
void findavgTime(int prcs[], int n, int bt[])
{
    int wt[n], tat[n], totalWait = 0, totalTAT = 0;

    // To find waiting time of all processes
    findWT(prcs, n, bt, wt);

    // To find turn around time for all processes
    findTAT(prcs, n, bt, wt, tat);

    cout << "Processes  "<< " Burst Time  "<< " Wait Time  "<< " Turn-Around-Time\n";

    //Calculate the total time spent waiting and the total time spent turning around.
    for (int i = 0; i < n; i++)
    {
        totalWait = totalWait  + wt[i];
        totalTAT = totalTAT + tat[i];
        cout << "   " << i + 1 << "\t\t" << bt[i] << "\t\t "
             << wt[i] << "\t\t  " << tat[i] << endl;
    }

    cout << "Avg waiting time = "
         << (float)totalWait  / (float)n;
    cout << "\nAvg turn around time = "
         << (float)totalTAT / (float)n;
}

int main()
{
    //processes
    int prcs[] = {8 , 9, 10};
    int n = sizeof prcs / sizeof prcs[0];

    //Burst time
    int burstTime[] = {8, 3, 6};

    findavgTime(prcs, n, burstTime);
    return 0;
}