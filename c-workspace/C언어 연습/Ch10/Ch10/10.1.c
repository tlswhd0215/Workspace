#include <stdio.h>

struct birthday {//구조체 정의
	int year;
	int month;
	int day;//구조체 요소들
};
struct birthday my = { 2001,02,15 };//구조체 변수를 선언하고 초기화
int main()
{
	printf("생년월일 : %d년 %d월 %d일생", my.year, my.month, my.day);//구조체 변수 참조

	return 0;
}