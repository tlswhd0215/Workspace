#include <stdio.h>
int main()
{
	int no = 100, count = 20;//���� ���� �� �ʱ�ȭ
	printf("%d", no > count);//'no�� count���� ũ��'�� ���̸� 1 ��� �����̸� 0 ���
	printf("%d", no < count * 4);//'no�� count*4���� �۴�'�� ���̸� 1 �����̸� 0 ���
	printf("%d", (no != 100) || (count >= 20));//'no !=100' �� 'count>=20' �� �ϳ��� ���̸� 1��� ��� �����̸� 0���
	printf("%d", (no <= 100) && (count > 20));//'no<=100'�� 'count>20'�� ��� ���̸� 1 ��� �ϳ��� �����̸� 0���
	return 0;
}