#include <stdio.h>
#define SIZE 40

void rand_arr(int*a, int size);
void frequency_arr(int *a, int size);
int fre1 = 0, fre2 = 0, fre3 = 0, fre4 = 0, fre5 = 0;

int main()
{
	int arr[SIZE] = { 0 };
	rand_arr(arr, SIZE);
	frequency_arr(arr, SIZE);
	printf("배열 내용 : \n");
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
		count++;

		if (count % 10 == 0)
			printf("\n");
	}
	printf("-----------------------------------------------\n값의 범위\t도수\t상대도수\n");
	printf("-----------------------------------------------\n");
	printf("150 ~ 159\t%d\t%g\n", fre1, (double)fre1 / SIZE);
	printf("160 ~ 169\t%d\t%g\n", fre2, (double)fre2 / SIZE);
	printf("170 ~ 179\t%d\t%g\n", fre3, (double)fre3 / SIZE);
	printf("180 ~ 189\t%d\t%g\n", fre4, (double)fre4 / SIZE);
	printf("190 ~ 199\t%d\t%g\n", fre5, (double)fre5 / SIZE);

	return 0;

}
void rand_arr(int*a, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		a[i] = rand() % 50 + 150;
	}
}
void frequency_arr(int *a, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		switch (a[i] / 10)
		{
		case 15:
			fre1++;
			break;
		case 16:
			fre2++;
			break;
		case 17:
			fre3++;
			break;
		case 18:
			fre4++;
			break;
		case 19:
			fre5++;
			break;
		}
	}
}
