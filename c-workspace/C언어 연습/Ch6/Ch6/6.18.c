#include <stdio.h>
int main()
{
	int sum = 0;//변수 선언
	for (int i = 1; i <= 100; i++)//i가 100까지 1씩 더해질때 반복문 실행
	{
		
		sum += i % 2 == 0 ? -i : i;;//i를 2로 나눈 나머지가 0일때 즉 짝수일때 합 sum에 -i를 더해주고 나머지가 0이 아닐때 즉 홀수일때 i를 더해줌
	}
	
	printf("합(1 - 2 + 3 - 4 + ... +99 - 100) : %d", sum);//sum출력
	
	return 0;
}