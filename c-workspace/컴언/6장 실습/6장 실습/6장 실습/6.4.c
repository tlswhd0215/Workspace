#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void divisors(int num);
int main() 
{
	int i;
	int num;

	srand((unsigned int)time(NULL));

	for (i = 0; i < 3; i++)
	{
		num = rand() % 1000 + 1;
		printf("%dÀÇ ¾à¼ö : ", num);
		divisors(num);
	}
}
void divisors(int num)
{
	int count = 0;
	for (int i = 1; i <= num; i++)
		if (num%i == 0)
		{
			printf("%d, ", i);
			count++;
		}
	printf(" => ÃÑ %d°³\n", count);
}