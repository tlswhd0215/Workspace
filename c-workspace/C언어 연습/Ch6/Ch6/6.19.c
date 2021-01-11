#include <stdio.h>
int main()
{
	int i = 1, j, sum = 0;//변수 선언
	while (i <= 10)
		//for(i=1;i<=10;1++)
		//i가 10이하일때 반복문 실행
	{
		for (j = 1; j <= i; j++)//j가 1부터 1씩 더해서 i이하일때 까지 반복문 실행
		{
			if (j == 1)//j가 1일때
				printf("%d", j);//첫번째 항이므로 +기호를 제외하고 출력
			else if (j % 2 == 0)//j가 짝수이면 
				printf("%d", -j);//-j출력
			else//j가 1이 아닌 홀수이면 
				printf("+%d", j);//+기호를 포함한 j출력
			//연산과정 출력
		}
		sum += (i % 2 == 0 ? -i : i);//연산결과 계산 i가 짝수면 -i로 i가 홀수면 i로 sum에 더함
		printf(" = %d\n", sum);//sum출력
		i++;//i에 1을 더함
		
	}
	return 0;
}