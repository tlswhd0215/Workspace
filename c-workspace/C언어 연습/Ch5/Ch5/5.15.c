#include <stdio.h>
int main()
{
	int grade;
	printf("Enter Grade : ");
	scanf(" %d", &grade);
	if (grade >= 1 && grade <= 7)
	{
		switch (grade)
		{
		case(1):
			printf("���� ���߾��.");
			break;
		case(2):
		case(3):
			printf("���߾��.");
			break;
		case(4):
		case(5):
			printf("����ؾ� �ھ��.");
			break;
		case(6):
		case(7):
			printf("���� ���� ����ؾ� �ھ��.");
			break;
		}
	}
	else
		printf("error");
	return 0;
}