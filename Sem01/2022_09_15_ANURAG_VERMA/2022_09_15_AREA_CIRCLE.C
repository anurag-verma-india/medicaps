#include <stdio.h>

int main() {
	// find the area of a circle
	float radius, area;
	printf("Type the radius of your circle: ");
	scanf("%f", &radius);
	area = 3.14 * ( radius * radius);
	printf("Area of your circle is= %f", area);
	return 0;
}
