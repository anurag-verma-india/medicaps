#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

void linkedListTraversal(Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    Node *head;
    Node *second;
    Node *third;

    // Allocate memeory for linked list in heap
    head = (Node *) malloc(sizeof(Node));
    second = (Node *) malloc(sizeof(Node));
    third = (Node *) malloc(sizeof(Node));

    // Declare the list
    head->data = 1;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 5;
    third->next = NULL;

    linkedListTraversal(head);

}