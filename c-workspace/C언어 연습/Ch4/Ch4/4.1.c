#include <stdio.h>
int main()
{
	int a, b;//���� ����
	printf("a : ");
	scanf(" %d", &a);//������ ������ �����͸� �Է¹���
	printf("b : ");
	scanf(" %d", &b);//������ ������ �����͸� �Է¹���
	double sum = (double)(a + b) / (a - b);//������ ������� �Ǽ������� ��ȯ
	printf("(a + b)/(a - b) = %lf", sum);//������ ����� ���� �����
	return 0;
}