#include <stdio.h>
#include <string.h>

int main(){
    printf("---------------------------------------------------------\n");
    char str1[20] = "My name is ";
    char str2[20] = "Anurag";
    // strcpy(str2, str1); // <--
    // puts(str2);
    strcat(str1, str2); // <--
    puts(str1);
    printf("\n---------------------------------------------------------");
}