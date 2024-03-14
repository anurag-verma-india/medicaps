#include <iostream>
using namespace std;

// Structure to represent a process
struct Process {
    int process_id;
    int burst_time;
    int priority;
    int turn_around_time;
    int waiting_time;
    struct Process* next;
    struct Process* prev;
};

// Function to create a new process
Process* createProcess(int pid, int burst, int priority) {
    Process* newProcess = new Process;
    newProcess->process_id = pid;
    newProcess->burst_time = burst;
    newProcess->priority = priority;
    newProcess->turn_around_time = 0;
    newProcess->waiting_time = 0;
    newProcess->next = nullptr;
    newProcess->prev = nullptr;
    return newProcess;
}

// Function to insert a process into the linked list based on priority
void insertProcess(Process*& head, Process* newProcess) {
    if (head == nullptr) {
        head = newProcess;
        return;
    }
    Process* current = head;
    while (current->next != nullptr && current->next->priority > newProcess->priority)
        current = current->next;

    newProcess->next = current->next;
    if (current->next != nullptr)
        current->next->prev = newProcess;
    current->next = newProcess;
    newProcess->prev = current;
}

// Function to calculate turn around time
float calc_turn_around_time(Process* head, int number_of_processes) {
    float turn_around_time_sum = 0;
    Process* current = head;
    while (current != nullptr) {
        turn_around_time_sum += current->turn_around_time;
        current = current->next;
    }
    return (turn_around_time_sum / number_of_processes);
}

// Function to calculate waiting time
float calc_waiting_time(Process* head, int number_of_processes) {
    float waiting_time_sum = 0;
    Process* current = head;
    while (current != nullptr) {
        waiting_time_sum += current->waiting_time;
        current = current->next;
    }
    return (waiting_time_sum / number_of_processes);
}

// Function to create Gantt chart using doubly linked list
void printGanttChart(Process* head) {
    cout << "--- Gantt Chart ---" << endl;
    Process* current = head;
    while (current != nullptr) {
        cout << "P" << current->process_id << " -> ";
        current = current->next;
    }
    cout << "End" << endl;
}

int main() {
    cout << endl << "--- Priority CPU Scheduling ---" << endl << endl;
    Process* head = nullptr;

    // Create processes with different priorities
    insertProcess(head, createProcess(1, 20, 3)); // Lowest priority
    insertProcess(head, createProcess(2, 5, 2));
    insertProcess(head, createProcess(3, 10, 1)); // Highest priority

    // Create a new list with processes sorted by priority
    Process* newHead = nullptr;
    Process* current = head;
    while (current != nullptr) {
        insertProcess(newHead, createProcess(current->process_id, current->burst_time, current->priority));
        current = current->next;
    }

    // Print Gantt chart based on sorted list
    printGanttChart(newHead);

    // Print results table with priorities
    cout << endl << "PID\tBT\tPriority\tTAT\t_WT" << endl;
    current = newHead;
    while (current != nullptr) {
        cout << current->process_id << "\t" << current->burst_time << "\t"
            << current->priority << "\t\t"
            << current->turn_around_time << "\t" << current->waiting_time << endl;
        current = current->next;
    }
    cout << endl;

    // Free allocated memory for both lists
    while (head != nullptr) {
        Process* temp = head;
        head = head->next;
        delete temp;
    }
    while (newHead != nullptr) {
        Process* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
