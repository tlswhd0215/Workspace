#include <stdio.h>

int main()
{
	double num;//변수를 선언한다
	printf("실수값을 입력하세요 : ");//제시문을 출력한다
	scanf(" %lf", &num);//데이터를 입력받아 변수에 할당한다
	printf("결과 : %0.2lf", num / 2);//변수의 1/2의 값을 소수점 아래 둘째자리까지 출력한다
	return 0;
}