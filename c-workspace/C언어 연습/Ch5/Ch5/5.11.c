#include <stdio.h>
int main()
{
	int num;
	printf("������ �Է� : ");
	scanf(" %d", &num);
	if (num % 2 == 0)
		printf("%d�� ¦���Դϴ�.", num);
	else
		printf("%d�� Ȧ���Դϴ�.", num);
	return 0;
}