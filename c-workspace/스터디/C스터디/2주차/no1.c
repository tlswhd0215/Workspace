#include <stdio.h>
#include <math.h>

int main()
{
	unsigned int a, b;
	double c;

	printf("�� ���� ���̸� �Է����ּ���");
	scanf(" %d %d", &a, &b);
	a = a * a;
	b = b * b;
	c = a + b;

	c = sqrt(c);

	printf("������ ���� : %g", c);
}