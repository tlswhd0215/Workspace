#include <stdio.h>

int main() {
	int x1, x2, x3, x, y1, y2, y3, y;
	printf("Point 1 (x1,y1)? ");
	scanf(" %d %d", &x1, &y1);
	printf("Point 2 (x2,y2)? ");
	scanf(" %d %d", &x2, &y2);
	printf("Point 3 (x3,y3)? ");
	scanf(" %d %d", &x3, &y3);

	x = x1 ^ x2^x3;
	y = y1 ^ y2^y3;

	printf("\nPoint 4 is (%d, %d)\n", x, y);
}