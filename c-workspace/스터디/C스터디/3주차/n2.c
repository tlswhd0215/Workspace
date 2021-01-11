#include <stdio.h>

int main() {
	int num;
	printf("거스름돈? ");
	scanf(" %d", &num);

	printf("거스름돈 (10원미만 절사): %d\n", num / 10 * 10);
	if (num >= 50000)
	{
		printf(" 50000원 %d장\n", num / 50000);
		num = num % 50000;
	}
	if (num >= 10000)
	{
		printf(" 10000원 %d장\n", num / 10000);
		num = num % 10000;
	}
	if (num >= 5000)
	{
		printf("  5000원 %d장\n", num / 5000);
		num = num % 5000;
	}
	if (num >= 1000)
	{
		printf("  1000원 %d장\n", num / 1000);
		num = num % 1000;
	}
	if (num >= 500)
	{
		printf("   500원 %d개\n", num / 500);
		num = num % 500;
	}
	if (num >= 100)
	{
		printf("   100원 %d개\n", num / 100);
		num = num % 100;
	}
	if (num >= 50)
	{
		printf("    50원 %d개\n", num / 50);
		num = num % 50;
	}
	if (num >= 10)
	{
		printf("    10원 %d개\n", num / 10);
		num = num % 10;
	}
}