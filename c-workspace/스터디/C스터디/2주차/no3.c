#include <stdio.h>
#include <math.h>
int main() {
	int x1, y1, x2, y2;
	double distance;

	printf("������ ������ (x1, y1)? ");
	scanf(" %d %d", &x1, &y1);

	printf("������ ���� (x2, y2)? ");
	scanf(" %d %d", &x2, &y2);

	distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	printf("������ ����: %lf\n", distance);
}