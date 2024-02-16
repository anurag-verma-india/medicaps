#include <iostream>
using namespace std;

int main() {
  int processes[] = {1, 2, 3};
  int burst_times[] = {3, 1, 4};
  int number_of_processes = sizeof(processes) / sizeof(processes[0]);
  float average_waiting_time = 0;

  int waiting_time[number_of_processes];
  int cumulative_wt = 0;
  for (int i = 0; i < number_of_processes; i++) {
    waiting_time[i] = cumulative_wt;
    cumulative_wt += burst_times[i];
  }
  cout << "Process ID \t Burst Time \t Waiting Time" << endl;
  for (int i = 0; i < number_of_processes; i++) {
    cout << "        " << processes[i] << "        " << burst_times[i]
         << "                 " << waiting_time[i] << endl;
    average_waiting_time += waiting_time[i];
  }
  average_waiting_time /= number_of_processes;
  cout << "Average Waiting Time: " << average_waiting_time<<endl;
  return 0;
}