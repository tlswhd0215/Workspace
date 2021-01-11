#include <stdio.h>
/*int main()
{
	int score;
	printf("input score : ");
	scanf(" %d", &score);
	if (score >= 90 && score <= 100)
		printf("A");
	else if (score >= 80 && score <= 89)
		printf("B");
	else if (score >= 70 && score <= 79)
		printf("C");
	else if (score >= 60 && score <= 69)
		printf("D");
	else if (score < 60)
		printf("F");
	else
		printf("Wrong input");
	return 0;
}*/
int main()
{
	int score;
	printf("input score : ");
	scanf(" %d", &score);
	if (score >= 0 && score <= 100)
	{
		switch (score / 10)
		{
		case (10):
			printf("A");
			break;
		case(9):
			printf("A");
			break;
		case(8):
			printf("B");
			break;
		case(7):
			printf("C");
			break;
		case(6):
			printf("D");
		default:
			printf("F");
		}
	}
	else
		printf("error");
	return 0;
}
