#include <stdio.h>
int main()
{
	int grade;
	printf("��� �Է� : ");
	scanf(" %d", &grade);
	switch (grade)
	{
	case 1:
		printf("1�� : ����, ���, ��ǻ��, ������");
		break;
	case 2:
		printf("2�� : ����, ���, ��ǻ��");
		break;
	case 3:
		printf("3�� : ����, ���");
		break;
	case 4:
		printf("4�� : ����");
		break;
	default:
		printf("��ǰ ����");
		break;
	}
	return 0;
}