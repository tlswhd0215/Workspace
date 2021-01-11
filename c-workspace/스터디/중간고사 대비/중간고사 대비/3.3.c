#include <stdio.h>
int main()
{
	int num, i;
	printf("2와 9사이의 자연수 입력 : ");
	scanf(" %d", &num);

	for (i = 1; i <= 9; i++)
	{
		printf("%d x %d = %d",num, i, num*i);
		printf("\n");
	}
	return 0;
}