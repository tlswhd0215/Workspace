#include <stdio.h>
#include <math.h>
typedef struct point {
	int x, y;
}POINT;
typedef struct rectangle {
	POINT LT;
	POINT RB;
}RECT;
int FindArea(RECT A);
int main()
{
	int area;
	RECT abcd;
	printf("왼쪽 상단 점 입력(x,y): ");
	scanf(" %d %d", &abcd.LT.x, &abcd.LT.y);
	printf("오른쪽 하단 점 입력(x,y): ");
	scanf(" %d %d", &abcd.RB.x, &abcd.RB.y);

	area = FindArea(abcd);
	printf("직사각형의 면적 : %d", area);

	return 0;
}
int FindArea(RECT A)
{
	return abs(A.LT.x - A.RB.x)*abs(A.LT.y - A.RB.y);
}