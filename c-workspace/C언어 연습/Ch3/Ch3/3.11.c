#include <stdio.h>
int main()
{
	double num;
	printf("�Ǽ��� �Է��ϼ��� (�Ҽ��� 4�ڸ�����) : ");
	scanf(" %lf", &num);
	printf("�Ҽ��� 3�ڸ� : %.3f\n", num);
	printf("�Ҽ��� 2�ڸ� : %.2f\n", num);
	printf("�Ҽ��� 1�ڸ� : %.1f\n", num);
	return 0;
}