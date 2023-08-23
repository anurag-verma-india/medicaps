#include <stdio.h>

void main() {
    int i, a[5], b[5], len_arr= 5;
    printf("Enter elemets of the array\n");
    for(i = 0; i <= len_arr; i++) {
        printf("Enter a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("\n");
    // reversing array
    for(int i = 0; i <= len_arr; i++) {
        b[len_arr - i] = a[i];
    }
    printf("Reverse of the array is: ");
    for(int i = 0; i <= len_arr; i++) {
        printf("%d\t", b[i]);
    }   
}