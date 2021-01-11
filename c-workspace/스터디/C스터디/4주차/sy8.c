#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
int main()
{
	int size;
	char menu;

	while (1) {
		printf("---------------------------------\n");
		printf("1. 왼쪽 직각 삼각형 찍기\n");
		printf("2. 오른쪽 직각 삼각형 찍기\n");
		printf("3. 왼쪽 직각 역삼각형 찍기\n");
		printf("4. 오른족 직각 역삼각형 찍기\n");
		printf("5. 종료\n");
		printf("---------------------------------\n");

		do {
			printf("==> 메뉴 선택: ");
			scanf(" %c", &menu);
			if ('1' <= menu && menu <= '5')
				break;
			else
				printf("입력 오류!! 메뉴를 다시 선택해주세요\n");
		} while (1);
		if (menu == '5') {
			printf("프로그램을 종료합니다.\n");
			break;
		}

		printf("==> 삼각형 크기(line 수) 입력: ");
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
		system("pause"); //화면 상태 유지
		system("cls"); //화면 지우기
	}
}