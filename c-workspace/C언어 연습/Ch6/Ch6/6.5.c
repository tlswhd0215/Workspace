#include <stdio.h>
int main()
{
	int sum, i;//���� ����
	for (sum = 0, i = 1; i < 101; i++)//sum�� i�� ���� 0�� 1�� �ʱ�ȭ�ϰ� i�� 101���� ���� �������� i�� �����ϰ� 1�� �����ֵ��� �Ѵ�
		sum = sum + i;//for�� ������ �������� i�� sum�� ���Ѱ��� sum�� �����Ѵ�
	printf("�� : %d", sum);//sum�� ����Ѵ�
	return 0;
}