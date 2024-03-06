// check if time remains run P1
// check if time remains run P2
// P3
// P1
// P2

#include <iostream>
using namespace std;

class Process
{
public:
    int process_id, remaining_burst_time, completion_time, waiting_time;
    static int number_of_processes, time_quantum, cumulative_burst;
    static float turn_around_time_sum;
    Process(int process_id_in, int burst_time_in)
    {
        number_of_processes += 1;
        process_id = process_id_in;
        remaining_burst_time = burst_time_in;
        completion_time = 0;
        waiting_time = 0;
    }
    void update_completion_time(int time_to_add)
    {
        completion_time += time_to_add;
        turn_around_time_sum += (float)time_to_add;
    }
};
int Process::time_quantum = 5;
int Process::cumulative_burst = 0;
int Process::number_of_processes = 0;
float Process::turn_around_time_sum = 0;

float calc_completion_time(Process pro[], int size)
{
    int tq = Process::time_quantum;
    // calculating for every element
    for (int i = 0; i < size; i++)
    {
        int cumulative_burst = Process::cumulative_burst;
        // for(int j=0; )
        pro[i].completion_time = 0;
        while (cumulative_burst > 0)
        {
            while (pro[i].remaining_burst_time > 0)
            {
                if (pro[i].remaining_burst_time >= tq)
                {
                    pro[i].update_completion_time(tq);

                    pro[i].remaining_burst_time -= tq;
                    cumulative_burst -= tq;
                }
                else
                {
                    pro[i].update_completion_time(pro[i].remaining_burst_time);

                    pro[i].remaining_burst_time -= (pro[i].remaining_burst_time);
                    cumulative_burst -= pro[i].remaining_burst_time;
                }
            }
        }

        // pro[i].completion_time = 0;
        // for (int j = 0; j <= i; j++)
        // {
        //     pro[i].completion_time += pro[j].remaining_burst_time;
        // }
        // Process::turn_around_time_sum += (float)pro[i].completion_time;
    }
    return (Process::turn_around_time_sum / Process::number_of_processes);
}

float calc_waiting_time(Process &pro)
{
    float waiting_time_sum = 0;

    for (int i = 0; i < Process::number_of_processes; i++)
    {
        // pro.waiting_time = pro.completion_time - pro.remaining_burst_time;
        // waiting_time_sum += (float)pro.waiting_time;
    }
    return (waiting_time_sum / Process::number_of_processes);
}

int main()
{

    cout << endl
         << " --- Round Robin Scheduling --- " << endl;
    Process arr[3] = {
        Process(1, 20),
        Process(2, 5),
        Process(3, 10)};
    // calc_turn_around_time(arr, 3);
    cout << "PID"
         << "\t"
         << "_BT"
         << "\t"
         << "TAT" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout
            << arr[i].process_id
            << "\t"
            << arr[i].remaining_burst_time
            << "\t"
            << arr[i].completion_time
            << endl;
    }
    cout << endl;
    return 0;
}