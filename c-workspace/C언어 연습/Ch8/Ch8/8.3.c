#include <stdio.h>
int main()
{
	int val[5];
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		printf("%d¹øÂ° data input : ", i + 1);
		scanf(" %d", &val[i]);
		sum += val[i];
	}
	for (int i = 0; i < 5; i++)
	{
		printf("+%d", val[i]);
	}
	printf("= %d", sum);

	return 0;
}