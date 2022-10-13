#include <stdio.h>
main()
{
	int a=10,b=20,c=30;
	printf("%d", (a>b) && (a<b));
	printf("%d", (a>b) || (a<c));
	printf("%d", ! (a>b));
}