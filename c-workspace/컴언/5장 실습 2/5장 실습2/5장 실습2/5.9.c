#include <stdio.h>
#include <stdlib.h>
int main()
{
	int size;
	char menu;
	while(1)
	{
	printf("-------------------------------------------\n");
	printf("1. ���� ���� �ﰢ�� ���\n");
	printf("2. ������ ���� �ﰢ�� ���\n");
	printf("3. ���� ���� ���ﰢ�� ���\n");
	printf("4. ������ ���� ���ﰢ�� ���\n");
	printf("5. ����\n");
	printf("-------------------------------------------\n");

	do
	{
		printf("==> �޴� �Է� : ");
		scanf(" %c", &menu);
		if (menu == '1' || menu == '2' || menu == '3' || menu == '4' || menu == '5')
			break;
		else
			printf("�Է� ����!! �޴��� �ٽ� �������ּ���.\n");
	} while (1);

	if (menu=='5')
	{
		printf("���α׷��� �����մϴ�.");
		break;
	}

	printf("==> �ﰢ�� ũ��(line ��) �Է� : ");
	scanf(" %d", &size);
	printf("\n");

	switch (menu)
	{
	case '1':
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				printf("*");
			}
			printf("\n");
		}
		printf("\n");
		break;
	case '2':
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - i; j++)
				printf(" ");
			for (int j = 0; j < i + 1; j++)
				printf("*");
			printf("\n");
		}
		printf("\n");
		break;
	case '3':
		for (int i = size; i >=0; i--)
		{
			for (int j = 0; j < i; j++)
				printf("*");
			printf("\n");
		}
		break;
	case '4':
		for (int i = size; i >=0; i--)
		{
			for (int j = 0; j < size - i; j++)
				printf(" ");
			for (int j = 0; j < i; j++)
				printf("*");
			printf("\n");
		}
		break;
	}

	system("pause");
	system("cls");
}
return 0;
}