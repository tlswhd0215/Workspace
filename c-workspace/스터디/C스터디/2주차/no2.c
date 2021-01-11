#include <stdio.h>

int main() {
	int fp, sp, ep;
	double sale;

	printf("제품의 가격? ");
	scanf(" %d", &fp);

	printf("할인율(%%)? ");
	scanf(" %lf", &sale);

	sale /= 100;
	ep = fp * sale;
	sp = fp - ep;
	printf("할인가: %d원 (%d원 할인)\n", sp, ep);
}