#include <stdio.h>
int main()
{
	int a, b;
	printf("�� ���� �Է��ϼ��� : ");
	scanf("%d %d", &a, &b);
	a = (a > 0 ? a : -a);
	b = (b > 0 ? b : -b);
	printf("��� : %d", a + b);
	return 0;

}