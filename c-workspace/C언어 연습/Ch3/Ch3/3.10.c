#include <stdio.h>
int main()
{
	int temp;
	printf("ȭ���µ��� �Է��ϼ��� : ");
	scanf("%d", &temp);
	printf("�����µ��� %d�� �Դϴ�.", (temp - 32) * 5 / 9);
	return 0;
}