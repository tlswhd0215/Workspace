#include <stdio.h>
#define WIDTH 4
#define HEIGHT 4

void pyramid_arr(int a[][WIDTH], int wid, int hei);//숫자 피라미드 배열 함수
void print_arr2(int a[][WIDTH], int x, int y);//2차원 배열 출력 함수
int main()
{
	int arr[WIDTH][HEIGHT] = { 0 };//배열 선언

	pyramid_arr(arr, WIDTH, HEIGHT);
	print_arr2(arr, WIDTH, HEIGHT);

	return 0;
}
void pyramid_arr(int a[][WIDTH], int wid, int hei)
{
	int i, j, n = 1;
	for (i = 0; i < hei; i++)//중첩for문을 이용해서 숫자를 피라미드 형식으로 2차원 배열에 입력
	{
		for (j = 0; j <= i; j++)
		{
			a[i][j] = n;
			n++;
		}
	}
}
void print_arr2(int a[][WIDTH], int x, int y)
{
	int i, j;
	for (i = 0; i < y; i++)//중첩 for문을 이용해서 2차원 배열을 출력
	{
		for (j = 0; j < x; j++)
		{
			printf(" %d", a[i][j]);
		}
		printf("\n");
	}
}
