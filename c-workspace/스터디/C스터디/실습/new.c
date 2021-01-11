#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a, b, c;

	printf("KRW? ");
	scanf(" %lf", &a);

	printf("원/달러 환율? ");
	scanf(" %lf",&b);

	c = a / b;

	printf("KRW %f = USD %.2f", a, c);
}