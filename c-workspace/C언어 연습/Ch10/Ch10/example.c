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
	printf("���� ��� �� �Է�(x,y): ");
	scanf(" %d %d", &abcd.LT.x, &abcd.LT.y);
	printf("������ �ϴ� �� �Է�(x,y): ");
	scanf(" %d %d", &abcd.RB.x, &abcd.RB.y);

	area = FindArea(abcd);
	printf("���簢���� ���� : %d", area);

	return 0;
}
int FindArea(RECT A)
{
	return abs(A.LT.x - A.RB.x)*abs(A.LT.y - A.RB.y);
}