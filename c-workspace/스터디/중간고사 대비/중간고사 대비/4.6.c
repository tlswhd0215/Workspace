#include <stdio.h>
int main()
{
	
	char jun, gun;
quit:
	printf("��ȣ�� ���������� �Է� : ");
	scanf(" %c", &jun);
	printf("������ ���������� �Է� : ");
	scanf(" %c", &gun);
	if (jun == 's')
		switch (gun)
		{
		case 'r':
			printf("�������뿹 => ��ȣ");
			break;
		case 'p':
			printf("�������뿹 => ����");
			break;
		case 's':
			goto quit;
			break;
		default:
			printf("Error");
		}
	else if (jun == 'r')
		switch (gun)
		{
		case 'p':
			printf("�������뿹 => ��ȣ");
			break;
		case 's':
			printf("�������뿹 => ����");
			break;
		case 'r':
			goto quit;
			break;
		default:
			printf("Error");
		}
	else if (jun == 'p')
	{
		switch (gun)
		{
		case 's':
			printf("�������뿹 => ��ȣ");
			break;
		case 'r':
			printf("�������뿹 => ����");
			break;
		case 'p':
			goto quit;
			break;
		default:
			printf("Error");
		}
	}
	return 0;
}