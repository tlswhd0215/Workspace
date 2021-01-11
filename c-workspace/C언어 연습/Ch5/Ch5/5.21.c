#include <stdio.h>
int main()
{
	int price, count, change, count_500, count_100, count_50, count_10;
	printf("입금액 : ");
	scanf(" %d", &count);
	printf("물건값 : ");
	scanf(" %d", &price);
	change = count - price;
	printf("잔 금 : %d { ", change);
	if (change >= 500)
	{
		count_500 = change / 500;
		change = change % 500;
		if (count_500 != 0)
		{
			printf("500원 (%d) ", count_500);
		}
	}
	if (change >= 100 && change < 500)
	{
		count_100 = change / 100;
		change = change % 100;
		if (count_100 != 0)
		{
			printf("100원 (%d) ", count_100);
		}
	}
	if (change >= 50 && change < 100)
	{
		count_50 = change / 50;
		change = change % 50;
		if (count_50 != 0)
		{
			printf("50원 (%d) ", count_50);
		}
	}
	if (change >= 10 && change < 50)
	{
		count_10 = change / 10;
		change = change % 10;
		if (count_10 != 0)
		{
			printf("10원 (%d) ", count_10);
		}
	}
	printf(" }");
	return 0;
}