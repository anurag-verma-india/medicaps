// Round Robin CPU Scheduling

#include <iostream>
using namespace std;

void find_waiting_time(int processes[], int n,
                       int burst_time[], int waiting_time[], int time_quantum)
{
    int remaining_burst_time[n];
    for (int i = 0; i < n; i++)
        remaining_burst_time[i] = burst_time[i];
    int t = 0;
    while (1)
    {
        bool done = true;
        for (int i = 0; i < n; i++)
        {
            if (remaining_burst_time[i] > 0)
            {
                done = false;

                if (remaining_burst_time[i] > time_quantum)
                {
                    t += time_quantum;

                    remaining_burst_time[i] -= time_quantum;
                }

                else
                {
                    t = t + remaining_burst_time[i];
                    waiting_time[i] = t - burst_time[i];
                    remaining_burst_time[i] = 0;
                }
            }
        }
        if (done == true)
            break;
    }
}
void find_turn_around_time(int processes[], int n,
                           int burst_time[], int waiting_time[], int turn_around_time[])
{
    for (int i = 0; i < n; i++)
        turn_around_time[i] = burst_time[i] + waiting_time[i];
}
void find_average_time(int processes[], int n, int burst_time[],
                       int time_quantum)
{
    int waiting_time[n], turn_around_time[n], total_waiting_time = 0, total_turn_around_time = 0;
    find_waiting_time(processes, n, burst_time, waiting_time, time_quantum);
    find_turn_around_time(processes, n, burst_time, waiting_time, turn_around_time);
    cout << "Processes "
         << " Burst time "
         << " Waiting time "
         << " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_waiting_time = total_waiting_time + waiting_time[i];
        total_turn_around_time = total_turn_around_time + turn_around_time[i];
        cout << " " << i + 1 << "\t\t" << burst_time[i] << "\t "
             << waiting_time[i] << "\t\t " << turn_around_time[i] << endl;
    }
    cout << "Average waiting time = "
         << (float)total_waiting_time / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_turn_around_time / (float)n;
}
int main()
{

    cout << endl
         << "-------- Round Robin CPU Scheduling --------" << endl
         << endl;

    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {20, 5, 9};
    int time_quantum = 5;
    find_average_time(processes, n, burst_time, time_quantum);
    cout << endl
         << endl;
    return 0;
}