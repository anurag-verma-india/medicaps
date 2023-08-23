#include <stdio.h>

void main()
{
	int a;
	int *p;
	printf("Enter a number: ");
	scanf(" %d", a);
	p = &a;
	printf("Value of a is %d\n", a);
	printf("Location of a is %p\n", p);
	printf("Value of *p is %d\n", *p);
}