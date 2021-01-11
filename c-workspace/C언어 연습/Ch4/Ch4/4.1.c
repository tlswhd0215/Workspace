#include <stdio.h>
int main()
{
	int a, b;//변수 선언
	printf("a : ");
	scanf(" %d", &a);//변수에 정수형 데이터를 입력받음
	printf("b : ");
	scanf(" %d", &b);//변수에 정수형 데이터를 입력받음
	double sum = (double)(a + b) / (a - b);//수식의 계산결과를 실수형으로 변환
	printf("(a + b)/(a - b) = %lf", sum);//수식을 계산한 값을 출력함
	return 0;
}