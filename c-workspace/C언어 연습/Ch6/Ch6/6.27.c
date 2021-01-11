#include <stdio.h>
int main()
{
	int num, i;//변수 선언

	printf("양의 정수 입력 : ");//입력문 출력
	scanf(" %d", &num);//num입력

	for (i = 2; i <= num; i++)//2부터 num까지 i를 1씩 더하면서 반복문 실행
	{
		if (num%i == 0)//num를 i로 나누었을때 나머지가 0이면, 즉 i가 num의 약수면
			break;//반복문 종료
	}
	if (num == i)//만약에 num이 소수이면 for문이 i=num일때 종료되므로 num=i일때
		printf("입력한 %d는 소수입니다.", num);//소수
	else//i가 num이 되기전에 종료되면
		printf("입력한 %d는 소수가 아닙니다.", num);//소수가 아님

	return 0;
}