#include <stdio.h>
#define WIDTH 4
#define HEIGHT 4

void pyramid_arr(int a[][WIDTH], int wid, int hei);//���� �Ƕ�̵� �迭 �Լ�
void print_arr2(int a[][WIDTH], int x, int y);//2���� �迭 ��� �Լ�
int main()
{
	int arr[WIDTH][HEIGHT] = { 0 };//�迭 ����

	pyramid_arr(arr, WIDTH, HEIGHT);
	print_arr2(arr, WIDTH, HEIGHT);

	return 0;
}
void pyramid_arr(int a[][WIDTH], int wid, int hei)
{
	int i, j, n = 1;
	for (i = 0; i < hei; i++)//��øfor���� �̿��ؼ� ���ڸ� �Ƕ�̵� �������� 2���� �迭�� �Է�
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
	for (i = 0; i < y; i++)//��ø for���� �̿��ؼ� 2���� �迭�� ���
	{
		for (j = 0; j < x; j++)
		{
			printf(" %d", a[i][j]);
		}
		printf("\n");
	}
}
