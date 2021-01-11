#include <stdio.h>
int main()
{
	int i, j;//변수 선언
	for (i = 0; i <= 4; i++)//i가 4이하일때 반복문 실행하고 i에 1증가
	{
		for (j = 0; j <= i; j++)//j가 i이하일때 j에 1을 증가시키며 반복문 실행
		{
			printf("%d ", j);//j출력
		}
		printf("\n");//줄바꿈
	}

	for (i = 3; i >= 0; i--)//i가 0이상일때 반복문 실행하고 i에 1감소
	{
		for (j = 0; j <= i; j++)//j가 i이하일때 j에 1을 증가시키며 반복문 실행
		{
			printf("%d ", j);//j출력
		}
		printf("\n");//줄바꿈 
	}
	return 0;
}