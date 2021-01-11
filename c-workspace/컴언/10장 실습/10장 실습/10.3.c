#include <stdio.h>
#include <math.h>
typedef struct point {
	int x, y;
}POINT;
typedef struct rectangle {
	POINT p1;
	POINT p2;
}RECT;
double CoumputeArea(RECT r);
int isSquare(RECT r);
int main()
{
	int square;
	double area;
	RECT abcd;
	printf("�簢���� �밢 �� ��ǥ �Է�\n");
	printf("ù��° �� ��ǥ: ");
	scanf(" %d %d", &abcd.p1.x, &abcd.p1.y);
	printf("�ι�° �� ��ǥ: ");
	scanf(" %d %d", &abcd.p2.x, &abcd.p2.y);

	area = CoumputeArea(abcd);
	printf("�簢���� ����: %.2f\n", area);

	square = isSquare(abcd);
	if (square == 1)
	{
		printf("�Է��Ͻ� �簢���� ���簢���Դϴ�.\n");
	}
	else 
	{
		printf("�Է��Ͻ� �簢���� ���簢���Դϴ�.\n");
	}
}
double CoumputeArea(RECT r)
{
	return (double)abs(r.p1.x - r.p2.x)*abs(r.p1.y - r.p2.y);
}
int isSquare(RECT r) 
{
	return (abs(r.p1.x - r.p2.x) == abs(r.p1.y - r.p2.y));
	
}