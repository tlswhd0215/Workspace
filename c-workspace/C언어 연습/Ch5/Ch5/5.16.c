#include <stdio.h>
int main()
{
	char ch;//변수 선언
	printf("영문자 입력 : ");//입력란 출력
	scanf(" %c", &ch);//영문자 입력
	switch (ch)//ch에 입력된 값에 따라 알맞은 case를 실행
	{
	case 'b'://b일 경우
	case 'B'://B일 경우
		printf("BASIC");//BASIC을 출력
		break;//switch문 종료
	case 'c'://c일경우
	case 'C'://C일경우
		printf("COBOL");//COBOL을 출력
		break;//switch문 종료
	case 'f'://f일경우
	case 'F'://F일경우
		printf("FORTRAN");//FORTRAN을 출력
		break;//switch문 종료
	case 'ㅣ'://l일 경우
	case 'L'://L일경우
		printf("LISP");//LISP을 출력
	case 'p'://p일 경우
	case 'P'://P일 경우
		printf("Pascal");//PASCAL을출력
		break;//switch문 종료
	default://위의 case에 해당하지 않을경우
		printf("Invalid Input");
	}
	return 0;
}