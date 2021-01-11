#include <stdio.h>
int main()
{
	int no1, no2, diff;//변수 선언
	printf("두 수 입력 : ");//입력 지시문 출력
	scanf(" %d %d", &no1, &no2);//no1과 no2를 입력받음
	if (no1 < no2)//no1이 no2보다 작은 범위에서
		diff = no2 - no1;//diff에 값을 지정
	else if (no1 >= no2)//else if를 사용해 위의 경우가 아니라 no1이 no2이상일 경우에
		diff = no1 - no2;//diff 지정
	printf("두 수의 차 : %d", diff);//diff 출력
	return 0;
}