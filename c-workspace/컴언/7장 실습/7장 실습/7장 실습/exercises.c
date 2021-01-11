#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void num(int arr[],int size);
int main()
{
	int arr[10];
	int i;
	srand((unsigned int)time(NULL));
	
	num(arr,10);

	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
void num(int arr[],int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100;
}