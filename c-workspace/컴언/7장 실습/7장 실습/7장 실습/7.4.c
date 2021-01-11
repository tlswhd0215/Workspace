#include <stdio.h>
#include <limits.h>

#define SIZE 10

int max = INT_MIN, min = INT_MAX;
void insert_arr(int*a,int size);
void maxmin_arr(int*a, int size);

int main()
{
	int arr[SIZE] = { 0 };
	insert_arr(arr, SIZE);
	maxmin_arr(arr, SIZE);

	printf("�ִ밪 : %d\n�ּҰ� : %d", max, min);

	return 0;
}
void insert_arr(int*a, int size)
{
	int i;
	printf("���� %d�� �Է� : ",size);
	for (i = 0; i < size; i++)
	{
		scanf(" %d", &a[i]);
	}
}
void maxmin_arr(int*a, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
}