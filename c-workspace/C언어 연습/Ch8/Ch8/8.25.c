#include <stdio.h>
int main()
{
	int i;
	int arr[2][10] = { {1} };
	
	for (i = 0; i < 10; i++)
	{
		scanf(" %d", &arr[0][i]);
	}

	for (i = 0; i < 10; i++)
	{
		arr[1][i] = 1;
		for (int j = 0; j < 10; j++)
		{
			if (arr[0][j] > arr[0][i])
			{
				arr[1][i]++;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		printf(" %d", arr[1][i]);
	}
	return 0;
}