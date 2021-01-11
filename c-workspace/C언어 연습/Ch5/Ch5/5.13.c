#include <stdio.h>
int main()
{
	int grade;
	printf("등급 입력 (1~8) : ");
	scanf(" %d", &grade);
	if (grade == 1 || grade == 2)
		printf("1 ~ 2 : 아주 잘했어요");
	else if (grade == 3 || grade == 4)
		printf("3 ~ 4 : 잘했어요");
	else if(grade == 5 || grade == 6)
		printf("5 ~ 6 : 노력해야 겠어요");
	else if (grade == 7 || grade == 8)
		printf("7 ~ 8 : 아주 노력해야 겠어요");

	return 0;

}