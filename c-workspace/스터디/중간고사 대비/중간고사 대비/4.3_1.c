#include <stdio.h>
int main()
{
	int num, i, j;
	printf("╪Ж ют╥б : ");
	scanf(" %d", &num);

	for (i = 0; i < num; i++)
	{
		for (j = num - i; j > 1; j--)
			printf(" ");
		for (j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
	for (i = num; i > 0; i--)
	{
		printf("   ");
		for (j = 0; j <i; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}