#include <stdio.h>
int main()
{
	int no = 100, count = 20;//변수 선언 및 초기화
	printf("%d", no > count);//'no가 count보다 크다'가 참이면 1 출력 거짓이면 0 출력
	printf("%d", no < count * 4);//'no가 count*4보다 작다'가 참이면 1 거짓이면 0 출력
	printf("%d", (no != 100) || (count >= 20));//'no !=100' 와 'count>=20' 중 하나라도 참이면 1출력 모두 거짓이면 0출력
	printf("%d", (no <= 100) && (count > 20));//'no<=100'과 'count>20'이 모두 참이면 1 출력 하나라도 거짓이면 0출력
	return 0;
}