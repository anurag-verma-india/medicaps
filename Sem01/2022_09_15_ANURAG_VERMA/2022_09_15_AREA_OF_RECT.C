#include <stdio.h>

int main() {
	// find the area of a rectangle
	float length, breadth, area;
	printf("Type the length of your rectangle: ");
	scanf("%f", &length);
	printf("Type the breadth of your rectangle: ");
	scanf("%f", &breadth);
	area = length * breadth;
	printf("Area of your rectangle is= %f", area);
	return 0;
}

