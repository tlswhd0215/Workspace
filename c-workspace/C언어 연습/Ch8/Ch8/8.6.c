#include <stdio.h>
#include <math.h>//pow와 sqrt사용
#define SIZE 10//배열의 크기

double ave,dev;//전역변수 선언
void insert_arr(double*arr,int size);//입력함수 선언
void average_arr(double*arr, int size);//평균값함수 선언
void deviation_arr(double*arr, int size);//표준편차함수 선언

int main()
{
	double arr[SIZE] = {0};//double형 배열 선언

	insert_arr(arr, SIZE);
	average_arr(arr, SIZE);
	deviation_arr(arr, SIZE);

	printf("평 균 값 : %g\n", ave);
	printf("표준편차 : %g",dev);

	return 0;
}
void insert_arr(double*a,int size)//size수만큼 임의의 수를 배열에 입력받는 함수
{
	for (int i = 0; i < size; i++)
	{
		printf("Input Data : ");
		scanf(" %lf", &a[i]);
	}
}
void average_arr(double*a, int size)//평균값을 구하는 함수 배열의 주소(*a)와 크기(size)를 입력받는다
{
	int i;
	double sum1 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += a[i];
	}
	ave = sum1/ size;
}
void deviation_arr(double*a, int size)//표준편차를 구하는 함수
{
	int i;
	double sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum2 += pow((a[i] - ave),2);
	}
	dev = sqrt(sum2 / size);
}