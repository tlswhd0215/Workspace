#include <stdio.h>

struct birthday {//����ü ����
	int year;
	int month;
	int day;//����ü ��ҵ�
};
struct birthday my = { 2001,02,15 };//����ü ������ �����ϰ� �ʱ�ȭ
int main()
{
	printf("������� : %d�� %d�� %d�ϻ�", my.year, my.month, my.day);//����ü ���� ����

	return 0;
}