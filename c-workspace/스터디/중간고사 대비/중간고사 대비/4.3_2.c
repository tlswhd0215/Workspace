#include <stdio.h>
int main()
{
	int num, i, j, n = 1;
	printf("���� �Է� : ");
	scanf(" %d", &num);

	for (i = 0; i < num; i++)
	{
		for (j = 0; j <= i;j++)
		{
			printf("%d", n);
			n++;
		}
		printf("\n");
	}
}