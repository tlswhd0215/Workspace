#include <stdio.h>
int main()
{
	char ch;
	printf("영문자를 입력하세요 : ");
	scanf(" %c", &ch);
	ch = (('a' <= ch) && (ch <= 'z') ? ch - 32 : ch);
	printf("결과 : %c", ch);
	return 0;
}