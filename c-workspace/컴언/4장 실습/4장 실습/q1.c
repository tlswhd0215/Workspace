#include <stdio.h>

int main()
{
	double mass, velo;
	printf(" ������ �ӷ��� �Է�\n");
	printf("����(kg) : ");
	scanf(" %lf", &mass);
	printf("�ӷ�(kg) : ");
	scanf(" %lf", &velo);
	printf("������� : %f J", mass * velo * velo / 2);
	return 0;
}