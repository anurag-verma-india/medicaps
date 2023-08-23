#include <stdio.h>
 int main(){
    int startingNum, endingNum = 15, sum;
    for (startingNum=7; startingNum <= endingNum; startingNum++)
    {
        sum += startingNum;
    };
    printf("\nSum of numbers from 7 to 15 is %d\n\n", sum );
 }