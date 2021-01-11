#include <stdio.h>
int main()
{
	int A, B, i, j=0, n, num=0;
	printf("2보다 크거나 같은 두 자연수 A, B 입력 (단, A < B)\n");
	printf("A : ");
	scanf(" %d", &A);
	printf("B : ");
	scanf(" %d", &B);
	for (n = A+1; n < B; n++)
	{
		j = 0;
		if (n == 2)
		{
			printf("2 ");
			num++;
		}
		for (i = 2; i <= n; i++)
		{
			if (n%i == 0)
			{
				break;
			}
			else
			{
				j++;
			}
			
		}
		if (j == n - 2)
			{
				printf("%d ", n);
				num++;
			}
	}
	printf("\n소수의 개수 : %d개", num);
	return 0;
}