#include <stdio.h>
int main()
{
	char ch1, ch2, ch3, result;
	printf("������ 3���� �Է��Ͻÿ� : ");
	scanf(" %c %c %c", &ch1, &ch2, &ch3);
	result = ((ch1 > ch2 ? ch2 : ch1) > ch3 ? ch3 : (ch1 > ch2 ? ch2 : ch1));
	printf("��� : %c", result);

	return 0;
}