#include <stdio.h>
#include <math.h>

int main()
{
	int a, b;
	double c;

	printf("�غ�? ");
	scanf(" %d", &a);
	printf("����? ");
	scanf(" %d", &b);

	c = a * a + b * b; //�� �κ��� �����ΰ� �ƴµ� ��� �ذ��ؾߵǴ��� �𸣰ھ��,,,,,

	printf("������ ����: %lf", sqrt(c));

}