#include <stdio.h>
int main()
{
	double F;
	printf("ȭ���µ� �Է�\nȭ���µ�(F) : ");
	scanf(" %lf", &F);
	printf("�����µ� : %f C", (F - 32) * 5 / 9);
	return 0;
	
}