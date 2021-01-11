#include <stdio.h>
#define MAX 50

int getArray(int p[]);
void printArray(const int p[], int size);
double computeAverage(const int p[], int size);
void copySquareArray(int p1[], const int p2[], int size);
void swapArray(int p1[], int p2[], int size);
void swap(int *a, int *b);
int main()
{
	int arr1[MAX], arr2[MAX];
	double average;
	int no;

	no = getArray(arr1);
	printf("\narr1 = ");
	printArray(arr1, no);

	average = computeAverage(arr1, no);
	printf("arr1의 평균 : %g \n", average);

	copySquareArray(arr2, arr1, no);
	printf("\n==== squareArray() 함수 호출 후 =====\n");
	printf("arr2 = ");
	printArray(arr2, no);

	swapArray(arr1, arr2, no);
	printf("\n==== swapArray() 함수 호출후 =====\n");
	printf("arr1 = ");
	printArray(arr1, no);
	printf("arr2 = ");
	printArray(arr2, no);

	return 0;
}
int getArray(int p[])
{
	int size;
	printf("몇개의 정수를 입력하시겠습니까? ");
	scanf("%d", &size);
	printf("%d개의 정수 입력 : ",size);
	for (int i = 0; i < size; i++)
	{
		scanf(" %d", (p + i));
	}
	return size;
}
void printArray(const int p[], int size)
{
	printf("{");
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
			printf("%d", p[i]);
		else
			printf("%d, ", p[i]);
	}
	printf("}\n");
}
double computeAverage(const int p[], int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += *(p++);
	}
	return (double)sum / size;
}
void copySquareArray(int p1[], const int p2[], int size)
{
	for (int i = 0; i < size; i++)
	{
		p1[i] = p2[i] * p2[i];
	}
}
void swapArray(int p1[], int p2[], int size)
{
	for (int i = 0; i < size; i++)
	{
		swap(&p1[i], &p2[i]);
	}
}
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
