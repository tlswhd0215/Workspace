#include <stdio.h>
int main()
{
	int grade;
	printf("등수 입력 : ");
	scanf(" %d", &grade);
	switch (grade)
	{
	case 1:
		printf("1등 : 상패, 상금, 컴퓨터, 프린터");
		break;
	case 2:
		printf("2등 : 상패, 상금, 컴퓨터");
		break;
	case 3:
		printf("3등 : 상패, 상금");
		break;
	case 4:
		printf("4등 : 상패");
		break;
	default:
		printf("상품 없음");
		break;
	}
	return 0;
}