#include <iostream>
using namespace std;

void find_waiting_time(int processes[], int n,
                       int bt[], int wt[], int time_quantum)
{
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];
    int t = 0;
    while (1)
    {
        bool done = true;
        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false;

                if (rem_bt[i] > time_quantum)
                {
                    t += time_quantum;

                    rem_bt[i] -= time_quantum;
                }

                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == true)
            break;
    }
}
void find_turn_around_time(int processes[], int n,
                           int bt[], int wt[], int turn_around_time[])
{
    for (int i = 0; i < n; i++)
        turn_around_time[i] = bt[i] + wt[i];
}
void find_average_time(int processes[], int n, int bt[],
                       int time_quantum)
{
    int wt[n], turn_around_time[n], total_waiting_time = 0, total_turn_around_time = 0;
    find_waiting_time(processes, n, bt, wt, time_quantum);
    find_turn_around_time(processes, n, bt, wt, turn_around_time);
    cout << "Processes "
         << " Burst time "
         << " Waiting time "
         << " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_waiting_time = total_waiting_time + wt[i];
        total_turn_around_time = total_turn_around_time + turn_around_time[i];
        cout << " " << i + 1 << "\t\t" << bt[i] << "\t "
             << wt[i] << "\t\t " << turn_around_time[i] << endl;
    }
    cout << "Average waiting time = "
         << (float)total_waiting_time / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_turn_around_time / (float)n;
}
int main()
{

    cout << endl
         << "Round Robin CPU Scheduling " << endl
         << endl;

    int processes[] = {1, 2, 3, 4, 5};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {10, 20, 30, 40, 15};
    int time_quantum = 7;
    find_average_time(processes, n, burst_time, time_quantum);
    cout << endl
         << endl;
    return 0;
}
