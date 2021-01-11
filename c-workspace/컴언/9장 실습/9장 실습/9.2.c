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
			printf("\n가위<0>/바위<1>/보<2>/게임종료<-1> 입력: ");
			scanf(" %d", &user);
			if (user != 0 && user != 1 && user != 2 && user != -1)
			{
				printf("입력오류!! 0,1,2 또는 -1입력\n");
			}
		} while (user != 0 && user != 1 && user != 2 && user != -1);
		if (user == -1)
		{
			printf("가위바위보 게임을 종료합니다.");
			break;
		}
		printf("You: ");
		if (user == 0)
			printf("가위\n");
		else if (user == 1)
			printf("바위\n");
		else if (user == 2)
			printf("보\n");
		printf("컴퓨터: ");
		if (computer == 0)
			printf("가위\n");
		else if (computer == 1)
			printf("바위\n");
		else if (computer == 2)
			printf("보\n");
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
		printf("%d전\t%d승\t%d무\t%d패\n", total, win, tie, lose);
		printf("----------------------------------------------\n");
	}
	return 0;
}