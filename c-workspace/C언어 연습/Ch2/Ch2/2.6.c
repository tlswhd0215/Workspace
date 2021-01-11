#include <stdio.h>
int main()
{
	int val;
	printf("0~255 사이의 정수 입력 : ");
	scanf("%d", &val);
	printf("ASCII값 %d의 영문자는 %c입니다.", val, val);
	return 0;
}