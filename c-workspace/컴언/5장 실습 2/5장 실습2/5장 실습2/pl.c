#include <stdio.h>
int main()
{
	int num, i, n = 0;

	printf("양의 정수 입력 : ");
	scanf(" %d", &num);

	for (i = 2; i < num; i++)
	{
		
		if (num%i == 0)
		{
			printf("소수가 아닙니다.");
			break;
		}
		n++;
	}
	if (n == num - 2)
		printf("소수입니다");
	return 0;
}