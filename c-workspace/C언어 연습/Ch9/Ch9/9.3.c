#include <stdio.h>

float add_div(int x, int y, int *z);//float/float�� ���� ����� float���̹Ƿ� �������� float�̴� 
int main()
{
	int add;//add�� ������ ���̹Ƿ� ���������� �������ش�
	float div;
	div = add_div(3, 5, &add);
	printf("�� : %d, ������ : %f\n", add, div);

	return 0;
}
float add_div(int x, int y, int *z)//���� �� ���� �����͸� ���޹���
{
	*z = x + y;//�Է¹��� �����Ͱ� ����Ű�� ������ ������ ���� ����
	return ((float)x / (float)y);//������ ����� ����
}