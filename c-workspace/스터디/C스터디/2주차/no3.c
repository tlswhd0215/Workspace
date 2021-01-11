#include <stdio.h>
#include <math.h>
int main() {
	int x1, y1, x2, y2;
	double distance;

	printf("직선의 시작점 (x1, y1)? ");
	scanf(" %d %d", &x1, &y1);

	printf("직선의 끝점 (x2, y2)? ");
	scanf(" %d %d", &x2, &y2);

	distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	printf("직선의 길이: %lf\n", distance);
}