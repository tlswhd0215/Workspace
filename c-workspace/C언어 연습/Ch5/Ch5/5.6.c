#include <stdio.h>
int main()
{
	char ch;//변수 선언
	printf("임의의 영문자 입력 : ");//입력란 제시
	scanf(" %c", &ch);//문자 입력
	if (('A' <= ch) && (ch <= 'Z'))//A와 Z 사이의 문자일 경우 아래 문장을 실행
		printf("대문자 %c입니다.", ch);//대문자라는 문장을 출력
	else if (('a' <= ch) && (ch <= 'z'))//a와 z사이의 문자일 경우 아래 문장을 실행
		printf("소문자 %c입니다.", ch);//소문자라는 문장을 출력
	else//그 외의 경우에 아래 문장을 실행
		printf("잘못된 입력입니다.");//잘못된 문장임을 출력
	return 0;
}