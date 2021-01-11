#include <stdio.h>
int main()
{
	double num;
	printf("실수를 입력하세요 (소수점 4자리까지) : ");
	scanf(" %lf", &num);
	printf("소수점 3자리 : %.3f\n", num);
	printf("소수점 2자리 : %.2f\n", num);
	printf("소수점 1자리 : %.1f\n", num);
	return 0;
}