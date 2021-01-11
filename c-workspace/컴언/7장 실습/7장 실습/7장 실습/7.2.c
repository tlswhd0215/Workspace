#include <stdio.h>
#define MAX 10
int main()
{
	int num[MAX], a, d,i;
	printf("첫 번째 항? ");
	scanf(" %d", &a);
	printf("공차? ");
	scanf(" %d", &d);
	printf("등차수열 :");
	for (i = 0; i < MAX; i++)
	{
		num[i] = a + d * i;
		printf(" %d", num[i]);
	}
	return 0;
}