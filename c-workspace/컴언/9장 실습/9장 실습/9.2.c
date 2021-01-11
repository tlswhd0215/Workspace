#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SCISSORS 0
#define ROCK 1
#define PAPER 2

int main()
{
	int computer;
	int user;
	int total = 0, win = 0, tie = 0, lose = 0;

	srand((unsigned int)time(NULL));

	while (1)
	{
		computer = rand() % 3;

		do
		{
			printf("\n����<0>/����<1>/��<2>/��������<-1> �Է�: ");
			scanf(" %d", &user);
			if (user != 0 && user != 1 && user != 2 && user != -1)
			{
				printf("�Է¿���!! 0,1,2 �Ǵ� -1�Է�\n");
			}
		} while (user != 0 && user != 1 && user != 2 && user != -1);
		if (user == -1)
		{
			printf("���������� ������ �����մϴ�.");
			break;
		}
		printf("You: ");
		if (user == 0)
			printf("����\n");
		else if (user == 1)
			printf("����\n");
		else if (user == 2)
			printf("��\n");
		printf("��ǻ��: ");
		if (computer == 0)
			printf("����\n");
		else if (computer == 1)
			printf("����\n");
		else if (computer == 2)
			printf("��\n");
		switch (user - computer)
		{
		case 0:
			tie++;
			total++;
			break;
		case 1:
		case -2:
			win++;
			total++;
			break;
		case 2:
		case -1:
			lose++;
			total++;
			break;
		}

		printf("----------------------------------------------\n");
		printf("%d��\t%d��\t%d��\t%d��\n", total, win, tie, lose);
		printf("----------------------------------------------\n");
	}
	return 0;
}