#include <stdio.h>
int main()
{
	float ave = 10.25, sum = 4.32;//변수 ave와 sum를 실수형 데이터로 선언하고 각각 10.25, 4.32로 초기화하였다.
	printf("%.2f + %.2f = %.2f\n", ave, sum, ave + sum);//%.2f를 이용하여 데이터를 소수점 아래 둘째자리까지만 출력하도록 하여 ave와 sum의 합을 나타내는 공식을 출력하였다.
	printf("%.2f - %.2f = %.2f\n", ave, sum, ave - sum);//%.2f를 이용하여 데이터를 소수점 아래 둘째자리까지만 출력하도록 하여 ave와 sum의 차를 나타내는 공식을 출력하였다.

	return 0;
}