#include <stdio.h>
#include <math.h>//pow�� sqrt���
#define SIZE 10//�迭�� ũ��

double ave,dev;//�������� ����
void insert_arr(double*arr,int size);//�Է��Լ� ����
void average_arr(double*arr, int size);//��հ��Լ� ����
void deviation_arr(double*arr, int size);//ǥ�������Լ� ����

int main()
{
	double arr[SIZE] = {0};//double�� �迭 ����

	insert_arr(arr, SIZE);
	average_arr(arr, SIZE);
	deviation_arr(arr, SIZE);

	printf("�� �� �� : %g\n", ave);
	printf("ǥ������ : %g",dev);

	return 0;
}
void insert_arr(double*a,int size)//size����ŭ ������ ���� �迭�� �Է¹޴� �Լ�
{
	for (int i = 0; i < size; i++)
	{
		printf("Input Data : ");
		scanf(" %lf", &a[i]);
	}
}
void average_arr(double*a, int size)//��հ��� ���ϴ� �Լ� �迭�� �ּ�(*a)�� ũ��(size)�� �Է¹޴´�
{
	int i;
	double sum1 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += a[i];
	}
	ave = sum1/ size;
}
void deviation_arr(double*a, int size)//ǥ�������� ���ϴ� �Լ�
{
	int i;
	double sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum2 += pow((a[i] - ave),2);
	}
	dev = sqrt(sum2 / size);
}