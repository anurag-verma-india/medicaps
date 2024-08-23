#include <iostream>
using namespace std;

int main() {
    int n, bt[20], wt[20], tat[20],at[20], i,j;
    float avg_wt=0, avg_tat=0;

    cout << "\nEnter total number of processes: ";
    cin >> n;

    cout << "\nEnter burst time of processes: \n";
    for(i=0;i<n;i++) {
        cout << "P["<< i << "]: ";
        cin >> bt[i];
    }

    cout << "\nEnter arrival time of processes: \n";
    for(i=0;i<n;i++){
        cout << "P["<< i<< "]: ";
        cin >> at[i];
    }

    wt[0] = 0;
    for(i=1;i<n;i++) {
        wt[i] = 0;
        for(j=0;j<i;j++) {
            wt[i]+=bt[j];
        }
        wt[i]-=at[i];
    }

    cout<<"\nPro.\tAT\tBT\tTAT\tWT";

    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i]-at[i];
        avg_wt += wt[i]-at[i];
        avg_tat+=tat[i];

        cout << "\nP[" << i+1<< "]"<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<tat[i]<<"\t"<<wt[i];
    }

    avg_wt /=n;
    avg_tat /= n;

    cout << "\nAverage waiting time: " << avg_wt;
    cout << "\nAverage turn around time: " << avg_tat << "\n";

    return 0;
}