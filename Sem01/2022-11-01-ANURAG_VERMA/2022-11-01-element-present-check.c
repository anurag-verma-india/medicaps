#include <stdio.h>

void main(){
    int arr[] = {2, 4, 6, 8, 10};
    int x = 8;
    int arrlen = sizeof arr[0];
    int isElementPresent = 0;
    for (int i=0; i< arrlen; i++)
    {
        if (arr[i] == x)
        {
            isElementPresent = 1;
            break;
        }
    }

    printf("\n");

    if(isElementPresent)
    {
        printf("%d is present in this array \n", x);
    } else {
        printf("%d is not present in this array \n", x);
    }
    printf("\n");
}