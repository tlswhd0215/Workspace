#include <stdio.h>
int main()
{
	int no, count;//���� ����
	printf("���� �Է��ϼ��� : ");//�Է¶� ���
	scanf(" %d", &no);//���� �Է�
	printf("shift�ϰ��� �ϴ� �� : ");//�Է¶� ���
	scanf(" %d", &count);//���� �Է�
	printf("��� : %d", no << count);//no�� �������� count��ŭ shift�� ���� ���
	return 0;
}