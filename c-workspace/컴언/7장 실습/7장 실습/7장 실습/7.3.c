#include <stdio.h>
#define SIZE 5

void swap(int *x, int *y);
int main()
{
	int data[SIZE] = { 7,3,9,5,1 };
	int i, j;
	int index;

	for (i = 0; i < SIZE - 1; i++)
	{
		index = i;
		for (j = SIZE-1; j > i; j--)
		{
			if (data[index] > data[j])
				index = j;
		}
		if (i != index)
			swap(&data[i],&data[index]);
	}
	printf("Á¤·Ä ÈÄ : ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", data[i]);
	printf("\n");

	return 0;
}
void swap(int*x,int*y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}