#include <stdio.h>
int main()
{
	int no1, no2, diff;//���� ����
	printf("�� �� �Է� : ");//�Է� ���ù� ���
	scanf(" %d %d", &no1, &no2);//no1�� no2�� �Է¹���
	if (no1 < no2)//no1�� no2���� ���� ��������
		diff = no2 - no1;//diff�� ���� ����
	else if (no1 >= no2)//else if�� ����� ���� ��찡 �ƴ϶� no1�� no2�̻��� ��쿡
		diff = no1 - no2;//diff ����
	printf("�� ���� �� : %d", diff);//diff ���
	return 0;
}