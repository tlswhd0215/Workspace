#include <stdio.h>

int main() {
	double principal, rate, sum,interest; //principal = 원금 rate= 이율 sum= 원리합계 interest = 이자
	printf("원금? ");
	scanf(" %lf", &principal);

	printf("연이율 (%%)? ");
	scanf(" %lf", &rate);
	rate /= 100;
	for (int i = 0; i < 10; i++)
	{
		interest = principal * rate;
		sum = interest + principal;
		principal = sum;
		printf("%2d년째 이자: %.2lf, 원리합계: %.2lf\n", i + 1, interest, sum);
	}
}