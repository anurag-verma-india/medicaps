#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int top = -1, inp_array[SIZE];
void push();
void pop();
void show();

int main()
{
    int option = 0;
    while(1)
    {
        // int a[40];
        // a[50] = 50;
        // printf("%d", a[3]);
        printf("\nChoose the operation to perform on stack\n");
        printf("1.Push\n2.Pop\n3.Show\n9.Exit\n: ");
        scanf(" %d", &option);
        printf("\n");
        switch(option)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            case 9:
                return 0;
            default:
                printf("Invalid Input");
        }
        printf("\n");
    }
    return 0;
}

void push()
{
    if(top>SIZE-1)
    {
        printf("Overflow");
    } else
    {
        top++;
        printf("Enter element number %d of %d element of stack: ", top+1, SIZE);\
        scanf(" %d", &inp_array[top]);
    }
}

void show()
{
    if(top<0)
    {
        printf("Underflow\n");
    } else
    {
        for(int i = top; i>=0; --i)
        {
            printf("Element number %d is %d\n", i+1, inp_array[i]);
        }
    }
}

void pop()
{
    if(top<0)
    {
        printf("Underflow\n");
    } else
    {
        top--;
    }
}