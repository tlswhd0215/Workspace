#include <stdio.h>
int main()
{
	int num;//���� ����
	double all, cost;//���� ����
	printf("���ǰ� : ");//���ǰ� �Է¶� ���
	scanf(" %lf", &cost);//cost�Է¹���
	printf("���� : ");//���� �Է¶� ��� 
	scanf(" %d", &num);//num�Է¹���
	all = cost * num;//all�� ���� ����
	switch (all >= 5000)//����'all>=5000'�� ���̸� 1 �����̸� 0
	{
	case 0://0�ΰ�� ��ü �ݾ��� 5000�̸��� ���
		printf("�� �� : %f", all);//���� �ݾ� ���
		break;//switch�� ����
	case 1://1�� ��� ��ü �ݾ��� 5000�� �̻��� ���
		printf("�� �� : %f", all*0.9);//10% ���ε� �ݾ��� ���
		break;//swotch�� ����
	}
	return 0;
}