#include <iostream>
#define NUMBER_OF_PROCESSES 3
using namespace std;

int main()
{
    // processes[][PID, BT, TAT, WT]
    int processes[NUMBER_OF_PROCESSES][5] = {
        {1, 24, 0, 0, 0},
        {2, 3, 0, 0, 0},
        {3, 3, 0, 0, 0}};
    int total_completion_time = 0;
    for (int i = 0; i < NUMBER_OF_PROCESSES; i++)
    {
        total_completion_time += processes[i][1];
    }
    cout << endl
         << total_completion_time << endl;


    while (total_completion_time != 0)
    {
        
        total_completion_time--;
    }
    cout<<endl<<total_completion_time<<endl;
    return 0;
}