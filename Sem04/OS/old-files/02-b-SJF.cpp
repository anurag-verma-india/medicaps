// SJF (Non Preemptive)

#include <iostream>
using namespace std;

float calc_turn_around_time(int burst_time[][5], int turn_around_time[][5], int number_of_processes)
{
    // Assuming Arriving time = 0
    float turn_around_time_sum = 0;
    for (int i = 0; i < number_of_processes; i++)
    {
        turn_around_time[i][2] = 0;
        for (int j = 0; j <= i; j++)
        {
            turn_around_time[i][2] += burst_time[j][1];
        }
        turn_around_time_sum += (float)turn_around_time[i][2];
    }
    return (turn_around_time_sum / number_of_processes);
}

float calc_waiting_time(int burst_time[][5], int turn_around_time[][5], int waiting_time[][5], int number_of_processes)
{
    float waiting_time_sum = 0;
    for (int i = 0; i < number_of_processes; i++)
    {
        waiting_time[i][3] = turn_around_time[i][2] - burst_time[i][1];
        waiting_time_sum += (float)waiting_time[i][3];
    }
    return (waiting_time_sum / number_of_processes);
}

void bubbleSortMulti(int arr[][5], int n, int to_sort_field)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j][to_sort_field] > arr[j + 1][to_sort_field])
                swap(arr[j], arr[j + 1]);
}

int main()
{
    cout << endl
         << "--- Shortest Job First (Non Preemptive) ---" << endl
         << endl;
    // process[process_id, burst_time, turn_around_time, waiting_time, priority]
    int process[3][5] = {
        {1, 20, 0, 0, 0},
        {2, 5, 0, 0, 0},
        {3, 10, 0, 0, 0}};

    int number_of_processes = sizeof(process) / sizeof(process[0]);

    // sort according to bust time
    bubbleSortMulti(process, number_of_processes, 1);

    // calculate TAT
    float avg_TAT = calc_turn_around_time(process, process, number_of_processes);

    // calculate WT
    float avg_WT = calc_waiting_time(process, process, process, number_of_processes);

    // print results table
    bubbleSortMulti(process, number_of_processes, 0);
    cout << "PID "
         << "\t"
         << "BT "
         << "\t"
         << "TAT "
         << "\t"
         << "_WT " << endl;
    for (int i = 0; i < number_of_processes; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            cout << process[i][k] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // print averages
    cout << "Average Turn Around time: " << avg_TAT << endl;
    cout << "Average Waiting Time: " << avg_WT << endl;

    cout << endl;
    return 0;
}