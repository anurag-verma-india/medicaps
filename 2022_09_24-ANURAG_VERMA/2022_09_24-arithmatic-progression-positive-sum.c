#include <stdio.h>

main(){
	int num, count, sum=0;
	printf("Enter a positive number: ");
	scanf("%d", &num);
	for(count=1;count<=num;count++)
	{
		sum+=count;
	}
	printf("Sum of all the numbers less than and equal to your number is  %d\n", sum);
}
