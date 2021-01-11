#include <stdio.h>
int main()
{
	int no, count;//변수 선언
	printf("값을 입력하세요 : ");//입력란 출력
	scanf(" %d", &no);//정수 입력
	printf("shift하고자 하는 값 : ");//입력란 출력
	scanf(" %d", &count);//정수 입력
	printf("결과 : %d", no << count);//no이 왼쪽으로 count만큼 shift된 값을 출력
	return 0;
}