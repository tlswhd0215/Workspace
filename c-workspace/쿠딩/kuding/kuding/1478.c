#include <stdio.h>
#include <math.h>
#include <limits.h>
int main()
{
	int i, j;
	double length = INT_MAX, distance;
	int arr[3][2] = { 0 };
	for (i = 0; i < 3 ; i++)
	{
		for (j = 0; j < 2; j++)
			scanf(" %d", &arr[i][j]);
	}

	for (i = 0; i < 3; i++)
	{
		if (i == 2)
		{
			distance = sqrt(pow((arr[2][0] - arr[0][0]), 2) + pow((arr[2][1] - arr[0][1]), 2));
		}
		else
			distance = sqrt(pow(arr[i][0] - arr[i + 1][0], 2) + pow(arr[i][1] - arr[i + 1][1], 2));
		if (length > distance)
		{
			length = distance;
		}
	}
	printf("%.4f", length);

	return 0;
}