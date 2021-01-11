#include <stdio.h>
#include <limits.h>
int main()
{
	int arr[7];
	int max = INT_MIN, min = INT_MAX;
	for (int i = 0; i < 7; i++)
	{
		printf("input data %d : ", i + 1);
		scanf("%d", &arr[i]);
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	printf("max: %d, min: %d", max, min);
	return 0;
}