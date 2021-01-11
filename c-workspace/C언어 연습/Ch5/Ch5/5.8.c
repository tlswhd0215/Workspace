#include <stdio.h>
int main()
{
	int time;
	printf("시간을 입력 : ");
	scanf(" %d", &time);
	if (time <= 12 && time >= 1)
		printf("오전 %d시", time);
	else if (time > 12 && time <= 24)
		printf("오후 %d시", time - 12);
	else
		printf("잘못된 입력");
	return 0;
}