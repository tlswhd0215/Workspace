#include <stdio.h>
int main()
{
	int num, sum = 0, ave, i = 0;//변수 선언
	while (1) //무한루프 생성
	{
		printf("숫자 입력 : ");//입력란 출력
		scanf(" %d", &num);//num입력받기
		sum = sum + num;//0으로 초기화된 sum에 입력받은 num을 더해줌
		i++;//num의 개수를 새기위해 0으로 초기화된 i에 1을 더해줌
		if (num == 0)//num에 0이 입력되면 
			break;//루프를 탈출
	}
	ave = sum / (i - 1);//ave를 num의 합 sum을 i-1로 나눈 값으로 지정, i-1인 이유는 마지막에 0이 입력된 경우를 제외
	printf("합 : %d  평균 : %d", sum, ave);//합과 평균을 출력
	return 0;
}