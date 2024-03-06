#include <iostream>

using namespace std;

int main()
{
    cout << endl
         << " --- Round Robin Scheduling --- " << endl
         << endl;
    int i, number_of_processes, time, remain, temps = 0, time_quantum;

    int waiting_time = 0, turn_around_time = 0;

    cout << "Enter the total number of process: ";
    cin >> number_of_processes;

    remain = number_of_processes;

    int arrival_time[number_of_processes];
    int burst_time[number_of_processes];
    int remaining_time[number_of_processes];

    cout << endl
        << "Assuming arrival times of all processes to be 0"
        <<endl
         << "Enter the -"
         << endl;
    for (i = 0; i < number_of_processes; i++)
    {
        // cout << "Arrival time for Process " << i + 1 << ": ";
        // cin >> arrival_time[i];
        arrival_time[i];
        cout << "Burst time for Process " << i + 1 << ": ";
        cin >> burst_time[i];
        remaining_time[i] = burst_time[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> time_quantum;

    cout << "\n\nProcess\t:Turnaround Time:Waiting Time\n\n";
    for (time = 0, i = 0; remain != 0;)
    {
        if (remaining_time[i] <= time_quantum && remaining_time[i] > 0)
        {
            time += remaining_time[i];

            remaining_time[i] = 0;
            temps = 1;
        }

        else if (remaining_time[i] > 0)
        {
            remaining_time[i] -= time_quantum;

            time += time_quantum;
        }

        if (remaining_time[i] == 0 && temps == 1)
        {
            remain--;
            // Desplaying the result of wating, turn around time:
            printf("Process{%d}\t:\t%d\t:\t%d\n", i + 1, time - arrival_time[i], time - arrival_time[i] - burst_time[i]);
            cout << endl;

            waiting_time += time - arrival_time[i] - burst_time[i];
            turn_around_time += time - arrival_time[i];
            temps = 0;
            break;
        }

        if (i == number_of_processes - 1)
            i = 0;
        else if (arrival_time[i + 1] <= time)
            i++;
        else
            i = 0;
    }

    cout << "Average waiting time " << waiting_time * 1.0 / number_of_processes << endl;
    cout << "Average turn around time " << turn_around_time * 1.0 / number_of_processes << endl;
    ;

    return 0;
}