#include <stdio.h>
int main()
{
	int a, b, i, temp;
	printf("�� �ڿ��� �Է�\n");
	printf("a : ");
	scanf(" %d", &a);
	printf("b : ");
	scanf(" %d", &b);

	for (i = 1; i <= (a > b ? b : a); i++)
	{
		if (a%i == 0 && b%i == 0)
			temp = i;
	}
	printf("�ִ����� : %d", temp);
	for (i = a * b; i >= (a > b ? a : b); i--)
	{
		if (i%a == 0 && i%b== 0)
			temp = i;
	}
	printf("�ּҰ���� : %d", temp);
	return 0;
}