#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *previous;
    int data;
    struct node *next;
}node;

int main()
{   
    node *head, *one, *two, *three;

    one = (node *)malloc(sizeof(node));
    two = (node *)malloc(sizeof(node));
    three = (node *)malloc(sizeof(node));

    one->data = 1;
    two->data = 2;
    three->data = 3;

    head->previous = NULL;
    head->next = one;

    one->previous= head;
    one->next = two;

    two->previous = one;
    two->next = three;

    three->previous=two;
    three->next = NULL;

    printf("%d\n", one->data);
    node *ptr = head;
    // while (ptr->next != NULL)
    // {
    //     printf("%d\n", ptr->data);
    //     ptr = ptr ->next;
    // }


    return 0;
}