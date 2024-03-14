// Function to create Gantt chart using doubly linked list
void printGanttChart(Process *head)
{
    cout << "--- Gantt Chart ---" << endl;
    Process *current = head;
    while (current != nullptr)
    {
        cout << "P" << current->process_id << " -> ";
        current = current->next;
    }
    cout << "End" << endl;
}