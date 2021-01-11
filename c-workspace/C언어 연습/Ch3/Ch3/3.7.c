#include <stdio.h>
int main()
{
	unsigned int no;// 입력받는 변수가 양의 정수이므로 데이터형을 unsigned int로 설정

	printf("양의 정수 : ");//입력할 데이터형 제시
	scanf(" %d", &no);//변수 no에 정수형 데이터를 입력받아 할당 
	printf("8진수 : %o\n", no);//변수 no를 8진수 정수형으로 출력하기 위해 변환문자 %o사용
	printf("16진수 : %x", no); //변수 no를 16진수 정수형으로 출력하기 위해 변환문자 %x사용

	return 0;
}