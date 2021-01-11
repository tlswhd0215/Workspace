#include <stdio.h>
#include <math.h>

int main()
{
	unsigned int a, b;
	double c;

	printf("두 변의 길이를 입력해주세요");
	scanf(" %d %d", &a, &b);
	a = a * a;
	b = b * b;
	c = a + b;

	c = sqrt(c);

	printf("빗변의 길이 : %g", c);
}