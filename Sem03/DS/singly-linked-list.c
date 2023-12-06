#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int printLinkedList(node *head)
{
    node *ptr;
    if (head->next == NULL)
    {
        printf("This is an empty list");
        return 0;
    }

    ptr = head->next;
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}

int printLast(node *head)
{
    node *ptr, *nextNode;
    if (head->next == NULL)
    {
        printf("This is an empty list");
        return 0;
    }

    ptr = head->next;
    while (ptr->next != NULL)
    {
        nextNode = ptr->next;
        if (nextNode->next == NULL)
        {
            printf("%d\n", nextNode->data);
        }

        // printf("%d", ptr->data);
        ptr = nextNode;
    }
    return 0;
}

int addAtLast(node *head)
{
    node *ptr, *nextNode, *lastNode;
    if (head->next == NULL)
    {
        printf("This is an empty list");
        return 0;
    }

    ptr = head->next;
    while (ptr->next != NULL)
    {
        nextNode = ptr->next;
        if (nextNode->next == NULL)
        {
            // printf("%d", nextNode->data);
            // lastNode->data = nextNode->data;
            lastNode = nextNode;
        }

        printf("%d", lastNode->data);
        // printf("%d", ptr->data);
        ptr = nextNode;
    }
    return 0;
}

int main()
{
    node *head, *one, *two, *three;

    one = (node *)malloc(sizeof(node));
    two = (node *)malloc(sizeof(node));
    three = (node *)malloc(sizeof(node));

    one->data = 1;
    two->data = 2;
    three->data = 3;

    one->next = two;
    two->next = three;
    three->next = NULL;

    head->next = one;

    printLinkedList(head);
    // printLast(head);
    // addAtLast(head);

    return 0;
}