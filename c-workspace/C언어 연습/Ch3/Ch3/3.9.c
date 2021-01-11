#include <stdio.h>
int main()
{
	int a, b, c, d, e;
	printf("정수 5개 입력\n");
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("평균 = %.1f", (double)(a + b + c + d + e) / 5);
	return 0;
}