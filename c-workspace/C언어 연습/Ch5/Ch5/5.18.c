#include <stdio.h>
int main()
{
	int score;
	printf("점수 입력 : ");
	scanf(" %d", &score);
	switch (score / 10)
	{
	case 10:
	case 9:
		printf("100 ~ 90 : A");
		break;
	case 8:
		printf("89 ~ 80 : B");
		break;
	case 7:
		printf("79 ~ 70 : C");
		break;
	case 6:
		printf("69 ~ 60 : D");
		break;
	default:
		printf("60점 미만 : F");
		break;
	}
	return 0;
}