// FCFS (Non preemptive)

#include <iostream>
using namespace std;

int main()
{
    cout << endl
         << "First Come First Serve Non Preemprive" << endl
         << endl;
    int arrival_time[] = {0, 1, 2};
    int burst_time[] = {20, 10, 5};

    int number_of_processes = sizeof(arrival_time) / sizeof(arrival_time[0]);

    // CT = sum(burst time of all processes before it)
    int completion_time[20];
    for (int i = 0; i < number_of_processes; i++)
    {
        completion_time[i] = 0;
        for (int j = 0; j <= i; j++)
        {
            completion_time[i] += burst_time[j];
        }
    }

    // TAT = CT - AT
    // [TAT = WT + BT]
    // WT = TAT - BT
    int turn_around_time[20], waiting_time[20];
    float turn_around_time_sum = 0, waiting_time_sum = 0;
    cout << "AT"
         << "\t"
         << "BT"
         << "\t"
         << "TAT"
         << "\t"
         << "WT" << endl;
    for (int i = 0; i < number_of_processes; i++)
    {

        turn_around_time[i] = 0;
        turn_around_time[i] = completion_time[i] - arrival_time[i];
        turn_around_time_sum += (float)turn_around_time[i];

        waiting_time[i] = 0;
        waiting_time[i] = turn_around_time[i] - burst_time[i];
        waiting_time_sum += (float)waiting_time[i];

        cout << arrival_time[i] << "\t" << burst_time[i] << "\t" << turn_around_time[i] << "\t" << waiting_time[i];
        cout << endl;
    }
    cout << endl;
    cout << "Average Turn Around time: " << (turn_around_time_sum / number_of_processes) << endl;
    cout << "Average Waiting time: " << (waiting_time_sum / number_of_processes) << endl;

    return 0;
}
