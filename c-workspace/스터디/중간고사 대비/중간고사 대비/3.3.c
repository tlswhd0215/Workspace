#include <stdio.h>
int main()
{
	int num, i;
	printf("2�� 9������ �ڿ��� �Է� : ");
	scanf(" %d", &num);

	for (i = 1; i <= 9; i++)
	{
		printf("%d x %d = %d",num, i, num*i);
		printf("\n");
	}
	return 0;
}