#include <stdio.h>
int main()
{
	double x, y;
	printf("��ǥ�� �Է�(x, y) : ");
	scanf(" %lf %lf", &x, &y);
	if (x > 0 && y > 0)
		printf("1��и鿡 �ֽ��ϴ�.");
	else if (x < 0 && y>0)
		printf("2��и鿡 �ֽ��ϴ�.");
	else if (x < 0 && y < 0)
		printf("3��и鿡 �ֽ��ϴ�.");
	else if (x > 0 && y < 0)
		printf("4��и鿡 �ֽ��ϴ�.");
	else if (y == 0 && x == 0)
		printf("�����Դϴ�.");
	else if (x == 0 && y != 0)
		printf("y������ ���Դϴ�.");
	else if (y == 0 && x != 0)
		printf("x������ ���Դϴ�.");
	

	return 0;

}