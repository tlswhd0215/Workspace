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
	printf("사각형의 대각 점 좌표 입력\n");
	printf("첫번째 점 좌표: ");
	scanf(" %d %d", &abcd.p1.x, &abcd.p1.y);
	printf("두번째 점 좌표: ");
	scanf(" %d %d", &abcd.p2.x, &abcd.p2.y);

	area = CoumputeArea(abcd);
	printf("사각형의 면적: %.2f\n", area);

	square = isSquare(abcd);
	if (square == 1)
	{
		printf("입력하신 사각형은 정사각형입니다.\n");
	}
	else 
	{
		printf("입력하신 사각형은 직사각형입니다.\n");
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