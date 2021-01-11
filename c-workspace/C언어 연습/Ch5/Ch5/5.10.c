#include <stdio.h>
int main()
{
	int a, b;
	printf("두 수를 입력하세요 : ");
	scanf("%d %d", &a, &b);
	a = (a > 0 ? a : -a);
	b = (b > 0 ? b : -b);
	printf("결과 : %d", a + b);
	return 0;

}