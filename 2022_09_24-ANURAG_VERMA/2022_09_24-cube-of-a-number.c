#include <stdio.h>

main(){
	int i,ctr;
	printf("input number of terms: ");
	scanf("%d", &ctr);
	for (i=1;i<=ctr;i++)
	{
	printf("Number is %d and cube of %d is %d\n", i, i, (i*i*i));
	}
}
