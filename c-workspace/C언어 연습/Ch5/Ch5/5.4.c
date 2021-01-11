#include <stdio.h>
int main()
{
	int score;
	char grade;
	printf("점수 입력 : ");
	scanf(" %d", &score);
	switch (score / 10)
	{
	case 10:
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	case 6:
		grade = 'D';
		break;
	default :
		grade = 'F';
		break;
	}
	printf("Grade = %c", grade);
	return 0;
}