#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

// process_id, burst_time, turn_around_time, waiting_time,
typedef struct processes
{
    int process_id, burst_time, turn_around_time, waiting_time;
} proc;

list<proc> processes_list = {};
list<proc> gantt_chart = {};

void insert_process(int process_id, int burst_time, int turn_around_time, int waiting_time)
{
    proc temp_process;
    temp_process.process_id = process_id;
    temp_process.burst_time = burst_time;
    temp_process.turn_around_time = turn_around_time;
    temp_process.waiting_time = waiting_time;
    processes_list.push_back(temp_process);
}




int main()
{
    insert_process(1,20,0,0);
    insert_process(2,5,0,0);
    insert_process(3,9,0,0);
    std::cout << "l = { ";
    for (proc p: processes_list)
        std::cout << p.process_id << ", ";
    std::cout << "};\n";

    // {1, 20, 0, 0, 2},
    //     {2, 5, 0, 0, 3},
    //     {3, 10, 0, 0, 1}};

    return 0;
}