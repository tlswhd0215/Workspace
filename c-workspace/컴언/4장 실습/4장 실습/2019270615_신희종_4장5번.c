#include <stdio.h>
#define PI 3.14159265
int main()
{
	int h, a;
	printf("����� ����(h)�� base������(a) �Է�\n");
	printf("����� ���� : ");
	scanf(" %d", &h);
	printf("base�� ������ : ");
	scanf(" %d", &a);
	printf("����� ü�� : %f\n", PI / 6 * h*(3 * a*a + h * h));
	printf("����� ǥ���� : %f", 2.0 * PI*h*(h / 3.0 + (PI / 6 * h*(3.0 * a*a + h * h)) / (PI * h * h)));
	return 0;
}
