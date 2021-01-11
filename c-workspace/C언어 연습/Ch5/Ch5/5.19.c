#include <stdio.h>
int main()
{
	double no1, no2;//변수 지정
	char op;//변수 지정
	printf("입력(연산기호, 숫자, 숫자) : ");//제시문 출력
	scanf(" %c %lf %lf", &op, &no1, &no2);//변수 입력받기
	switch (op)//op의 값에 따른 case별로 구문을 실행
	{
	case '+'://op에 +가 입력되었을 경우
		printf("연산결과 : %f", no1 + no2);//더하기 연산결과 출력
		break;//switch 구문 종료 
	case '-'://op에 -가 입력되었을 경우
		printf("연산결과 : %f", no1 - no2);//뺄셈연산결과 출력
		break;//switch 구문 종료 
	case '*'://op에 *가 입력되었을 경우
		printf("연산결과 : %f", no1 * no2);//곱셈연산결과 출력
		break;//switch 구문 종료 
	case '/'://op에 /가 입력되었을 경우
		printf("연산결과 : %f", no1 / no2);//나눗셈연산결과 출력
		break;//switch 구문 종료 
	default://옳지 않은 연산자가 입력되었을 경우
		printf("Invaid Input");//출력
	}
	return 0;
}