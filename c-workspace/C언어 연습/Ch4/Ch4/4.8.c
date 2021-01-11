#include <stdio.h>
int main()
{
	int no;//변수 선언
	printf("정수 : ");//입력란 출력
	scanf(" %d", &no);//정수 입력
	printf("나머지 : %d", no & 15);//입력된 정수를 비트연산자 &를 이용하여 16으로 나눈 나머지를 출력 
	return 0;
}