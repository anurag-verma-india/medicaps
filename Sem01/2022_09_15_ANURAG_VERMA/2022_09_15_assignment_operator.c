#include <stdio.h>
main()
{
	int a=5,c=10;
	printf("c=%d a=%d\n", c, a);
	c+=a;
	printf("c=%d a=%d\n", c, a);
	c-=a;
	printf("c=%d a=%d\n", c, a);
	c*=a;
	printf("c=%d a=%d\n", c, a);
	c%=a;
	printf("c=%d a=%d\n", c, a);
}
