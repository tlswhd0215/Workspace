#include <stdio.h>
int isLeapYear(int i);
int main()
{
	int count = 0;
	for (int j = 0; j < 50; j++)
	{
		printf("-");
	}
	printf("\n                2000~2150»çÀÌÀÇ À±³â\n");
	for (int j = 0; j < 50; j++)
	{
		printf("-");
	}
	printf("\n");
	for (int i = 2000; i <= 2150; i++)
	{
		if (isLeapYear(i) == 1)
		{
			printf(" %d", i);
			count++;
			if (count % 10 == 0 )
				printf("\n");
		}
		
		
	}
	return 0;
}
int isLeapYear(int i)
{
		if (i % 4 == 0 && i % 100 != 0)
		{
			return 1;
		}
		else if (i % 400 == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
}
