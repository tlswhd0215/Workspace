#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
int main()
{
	int size;
	char menu;

	while (1) {
		printf("---------------------------------\n");
		printf("1. ���� ���� �ﰢ�� ���\n");
		printf("2. ������ ���� �ﰢ�� ���\n");
		printf("3. ���� ���� ���ﰢ�� ���\n");
		printf("4. ������ ���� ���ﰢ�� ���\n");
		printf("5. ����\n");
		printf("---------------------------------\n");

		do {
			printf("==> �޴� ����: ");
			scanf(" %c", &menu);
			if ('1' <= menu && menu <= '5')
				break;
			else
				printf("�Է� ����!! �޴��� �ٽ� �������ּ���\n");
		} while (1);
		if (menu == '5') {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}

		printf("==> �ﰢ�� ũ��(line ��) �Է�: ");
		scanf(" %d", &size);

		switch (menu) {
		case '1':
			for (int i = 1; i <= size; i++) {
				for (int star = 1; star <= i; star++)
					printf("*");
				printf("\n");
			}
			break;
		case '2':
			for (int i = 1; i <= size; i++) {
				for (int gap = 1; gap <= i; gap++)
					printf(" ");
				for (int star = i; star > 0; star--)
					printf("*");
				printf("\n");
			}
			break;
		case '3':
			for (int i = 1; i <= size; i++) {
				for (int gap = 1; gap <= i; gap++)
					printf(" ");
				for (int star = i; star > 0; star--)
					printf("*");
				printf("\n");
			}
			break;
		case '4':
			for (int i = size; i > 0; i--) {
				for (int star = i; star > 0; star--)
					printf("*");
				printf("\n");
			}
			break;
		}
		system("pause"); //ȭ�� ���� ����
		system("cls"); //ȭ�� �����
	}
}