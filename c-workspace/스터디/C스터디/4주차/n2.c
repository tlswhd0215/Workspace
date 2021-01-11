#include <stdio.h>

int main() {
	int min,sum;

	printf("주차시간 (분)? ");
	scanf(" %d", &min);

	if (min <= 30)
		sum = 2000;
	else
		sum= 2000 + ((min - 31) / 10 + 1) * 1000;
	if (sum > 25000)
		sum = 25000;

	printf("주차 요금: %d원\n", sum);
}