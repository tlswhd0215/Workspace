#include <stdio.h>
int main()
{
	char ch;
	printf("�����ڸ� �Է��ϼ��� : ");
	scanf(" %c", &ch);
	ch = (('a' <= ch) && (ch <= 'z') ? ch - 32 : ch);
	printf("��� : %c", ch);
	return 0;
}