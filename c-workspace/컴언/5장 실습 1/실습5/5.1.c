#include <stdio.h>
int main()
{
	double x, y;
	printf("좌표를 입력(x, y) : ");
	scanf(" %lf %lf", &x, &y);
	if (x > 0 && y > 0)
		printf("1사분면에 있습니다.");
	else if (x < 0 && y>0)
		printf("2사분면에 있습니다.");
	else if (x < 0 && y < 0)
		printf("3사분면에 있습니다.");
	else if (x > 0 && y < 0)
		printf("4사분면에 있습니다.");
	else if (y == 0 && x == 0)
		printf("원점입니다.");
	else if (x == 0 && y != 0)
		printf("y축위의 점입니다.");
	else if (y == 0 && x != 0)
		printf("x축의의 점입니다.");
	

	return 0;

}