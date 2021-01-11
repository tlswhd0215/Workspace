#include <stdio.h>
int main()
{
	int sum, i;//변수 선언
	for (sum = 0, i = 1; i < 101; i++)//sum과 i를 각각 0과 1로 초기화하고 i가 101보다 작은 범위에서 i를 연산하고 1을 더해주도록 한다
		sum = sum + i;//for로 지정된 구간에서 i를 sum에 더한것을 sum에 대입한다
	printf("합 : %d", sum);//sum을 출력한다
	return 0;
}