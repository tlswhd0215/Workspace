#include <stdio.h>
int main()
{
	int num, sum = 0, ave, i = 0;//���� ����
	while (1) //���ѷ��� ����
	{
		printf("���� �Է� : ");//�Է¶� ���
		scanf(" %d", &num);//num�Է¹ޱ�
		sum = sum + num;//0���� �ʱ�ȭ�� sum�� �Է¹��� num�� ������
		i++;//num�� ������ �������� 0���� �ʱ�ȭ�� i�� 1�� ������
		if (num == 0)//num�� 0�� �ԷµǸ� 
			break;//������ Ż��
	}
	ave = sum / (i - 1);//ave�� num�� �� sum�� i-1�� ���� ������ ����, i-1�� ������ �������� 0�� �Էµ� ��츦 ����
	printf("�� : %d  ��� : %d", sum, ave);//�հ� ����� ���
	return 0;
}