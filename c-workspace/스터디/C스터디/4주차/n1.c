#include <stdio.h>

int main() {
	double principal, rate, sum,interest; //principal = ���� rate= ���� sum= �����հ� interest = ����
	printf("����? ");
	scanf(" %lf", &principal);

	printf("������ (%%)? ");
	scanf(" %lf", &rate);
	rate /= 100;
	for (int i = 0; i < 10; i++)
	{
		interest = principal * rate;
		sum = interest + principal;
		principal = sum;
		printf("%2d��° ����: %.2lf, �����հ�: %.2lf\n", i + 1, interest, sum);
	}
}