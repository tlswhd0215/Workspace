#include <stdio.h>

int main() {
	int num;
	printf("�Ž�����? ");
	scanf(" %d", &num);

	printf("�Ž����� (10���̸� ����): %d\n", num / 10 * 10);
	if (num >= 50000)
	{
		printf(" 50000�� %d��\n", num / 50000);
		num = num % 50000;
	}
	if (num >= 10000)
	{
		printf(" 10000�� %d��\n", num / 10000);
		num = num % 10000;
	}
	if (num >= 5000)
	{
		printf("  5000�� %d��\n", num / 5000);
		num = num % 5000;
	}
	if (num >= 1000)
	{
		printf("  1000�� %d��\n", num / 1000);
		num = num % 1000;
	}
	if (num >= 500)
	{
		printf("   500�� %d��\n", num / 500);
		num = num % 500;
	}
	if (num >= 100)
	{
		printf("   100�� %d��\n", num / 100);
		num = num % 100;
	}
	if (num >= 50)
	{
		printf("    50�� %d��\n", num / 50);
		num = num % 50;
	}
	if (num >= 10)
	{
		printf("    10�� %d��\n", num / 10);
		num = num % 10;
	}
}