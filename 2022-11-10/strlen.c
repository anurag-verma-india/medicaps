#include <stdio.h>
#include <string.h>

void main()
{
    char a[20] = "Program";
    char b[20] = {'p', 'r', 'o', 'g', 'r', 'a', 'm', '\0'};
    printf("Length of string a = %zu \n", strlen(a));
    printf("Length of string b = %zu \n", strlen(b));
}