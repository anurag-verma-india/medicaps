#include <stdio.h>

int main(){
	printf("What are your 3 favourate numbers: ");
	int num1, num2, num3;
	scanf("%d%d%d", &num1, &num2, &num3);
	float average = (num1 + num2 + num3)/3;
	printf("Average of the numbers you typed is: %f", average);
}
