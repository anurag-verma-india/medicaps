// Round Robin CPU Scheduling

#include <iostream>
#include <vector>
using namespace std;

typedef struct process
{
    int remaining_burst_time;
    int id;
} process;

int main()
{
    cout << endl
         << "--- Priority CPU Scheduling ---" << endl
         << endl;

    vector<process> ready_queue;
    process tempPro;
    int number_of_processes, tempInt;

    cout << "Enter the number of processes: ";
    cin >> number_of_processes;

    for (int i = 1; i <= number_of_processes; i++)
    {
        cout << "Enter process with id " << i << "'s burst time: ";
        cin >> tempPro.remaining_burst_time;
        tempPro.id = i;

        ready_queue.push_back(tempPro);
    }

    while (!ready_queue.empty())
    {
        for (process p : ready_queue)
        {
            cout << p.remaining_burst_time << "  ";
        }
        ready_queue.pop_back();
    }

    process process1;
    process1.id = 1;
    process1.remaining_burst_time = 20;

    // cout << (ready_queue.at(0)).remaining_burst_time << endl;

    return 0;
}