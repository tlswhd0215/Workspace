#include <stdio.h>
int main()
{
	int score;
	char grade;
	printf("���� �Է� : ");
	scanf(" %d", &score);
	if (score >= 90)
		grade = 'A';
	else if (score >= 80)
		grade = 'B';
	else if (score >= 70)
		grade = 'C';
	else if (score < 70)
		grade = 'F';
	printf("Grade = %c\n", grade);

	return 0;
}