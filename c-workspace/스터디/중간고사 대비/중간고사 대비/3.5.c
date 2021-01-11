#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c;
	double x1,x2;
	printf("자연수 a, b, c 입력\n");
	scanf(" %d %d %d", &a, &b, &c);
	if (pow(b, 2) - 4 * a*c > 0)
	{
		x1 = (-b + sqrt((pow(b, 2) - 4 * a * c)))/(2*a);
		x2 = (-b - sqrt((pow(b, 2) - 4 * a * c))) / (2 * a);
		printf("x = %f, %f",x1,x2);
	}
	else if (pow(b,2)-4*a*c==0)
	{
		x1 = (-b / (2 * a));
		printf("x = %f", x1);
	}
	else if (pow(b, 2) - 4 * a * c < 0)
	{
		printf("근이 없다.");
	}
	return 0;
}