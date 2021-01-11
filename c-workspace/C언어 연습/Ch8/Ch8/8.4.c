#include <stdio.h>
int main()
{
	int arr1[10] = { 1,3,5,7,9 };
	int arr2[10] = {5,7,9,1,3};
	for (int i = 0; i < 10; i++)
	{
		printf("%d\t%d\t%d", arr1[i], arr2[i], arr1[i] - arr2[i]);
	}
	return 0;
}