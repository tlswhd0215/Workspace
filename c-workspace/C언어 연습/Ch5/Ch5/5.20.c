#include <stdio.h>
int main()
{
	int num;//변수 선언
	double all, cost;//변수 선언
	printf("물건값 : ");//물건값 입력란 출력
	scanf(" %lf", &cost);//cost입력받음
	printf("개수 : ");//개수 입력란 출력 
	scanf(" %d", &num);//num입력받음
	all = cost * num;//all의 값을 정의
	switch (all >= 5000)//수식'all>=5000'이 참이면 1 거짓이면 0
	{
	case 0://0인경우 전체 금액이 5000미만인 경우
		printf("금 액 : %f", all);//원래 금액 출력
		break;//switch문 종료
	case 1://1인 경우 전체 금액이 5000원 이상인 경우
		printf("금 액 : %f", all*0.9);//10% 할인된 금액을 출력
		break;//swotch문 종료
	}
	return 0;
}