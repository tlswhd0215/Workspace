#include <stdio.h>
int main()
{
	int arr[4][5] = { {5,7,4,3},{6,1,8,3},{3,2,7,6} };
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			arr[i][4] += arr[i][j];
			arr[3][j] += arr[i][j];
			arr[3][4] += arr[i][j];
		}
	}
	for (i = 0; i < 4; i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}