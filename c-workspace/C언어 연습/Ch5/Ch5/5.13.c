#include <stdio.h>
int main()
{
	int grade;
	printf("��� �Է� (1~8) : ");
	scanf(" %d", &grade);
	if (grade == 1 || grade == 2)
		printf("1 ~ 2 : ���� ���߾��");
	else if (grade == 3 || grade == 4)
		printf("3 ~ 4 : ���߾��");
	else if(grade == 5 || grade == 6)
		printf("5 ~ 6 : ����ؾ� �ھ��");
	else if (grade == 7 || grade == 8)
		printf("7 ~ 8 : ���� ����ؾ� �ھ��");

	return 0;

}