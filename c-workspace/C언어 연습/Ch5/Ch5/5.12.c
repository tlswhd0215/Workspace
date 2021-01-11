#include <stdio.h>
int main()
{
	char ch1, ch2, ch3, result;
	printf("영문자 3개를 입력하시오 : ");
	scanf(" %c %c %c", &ch1, &ch2, &ch3);
	result = ((ch1 > ch2 ? ch2 : ch1) > ch3 ? ch3 : (ch1 > ch2 ? ch2 : ch1));
	printf("결과 : %c", result);

	return 0;
}