#include <stdio.h>
int main()
{
	int a, b;
	printf("두 수를 입력하세요 : ");
	scanf(" %d %d", &a, &b);
	printf("몫 : %d", a / b);
	printf("나머지 : %d", a%b);
	return 0;
}