#include <stdio.h>
int main()
{
	int a, b, c, d, e;
	printf("���� 5�� �Է�\n");
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("��� = %.1f", (double)(a + b + c + d + e) / 5);
	return 0;
}