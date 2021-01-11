#include <stdio.h>
#include <time.h>
#define SIZE 10//기호상수 선언  

void rand_arr(int*a, int size);//랜덤으로 숫자 지정하는 함수
void selection_sort_arr(int*a, int size);//선택정렬함수

int main()
{
	int i;
	int arr[SIZE] = { 0 };//배열 선언
	rand_arr(arr, SIZE);
	printf("배열의 내용 : ");//배열의 초기 내용 출력
	for (i = 0; i < SIZE; i++)
	{
		printf(" %d", arr[i]);
	}
	printf("\n");
	selection_sort_arr(arr, SIZE);

	return 0;
}
void rand_arr(int*a, int size)//중복값이 없이 배열 선언
{
	int i, n;
	srand((unsigned int)time(NULL));//실행시마다 다른 배열이 입력
	for (i = 0; i < size; i++)
	{
		a[i] = rand() % 90 + 10;//10~99의 수 중에서 랜덤으로 대입
		for (n = 0; n < i; n++)
		{
			if (a[i] == a[n])//중복된 값이 입력되었을 경우 다시 대입
			{
				i--;
				break;
			}
		}
	}
}
void selection_sort_arr(int*a, int size)//선택정렬
{
	int i, j, temp, n;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
			if (a[i] > a[j])//선택된 배열의 값이 뒤의 값보다 클 때 자리를 바꾼다
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		printf("%d회 : ", i + 1);//과정을 출력
		for (n = 0; n < size; n++)
			printf(" %d", a[n]);
		printf("\n");
	}
}