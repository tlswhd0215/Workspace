#include <stdio.h>
int main()
{
	int height, i, j;
	printf("높이 입력 : ");
	scanf(" %d", &height);

	for (i = 0; i < height; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}