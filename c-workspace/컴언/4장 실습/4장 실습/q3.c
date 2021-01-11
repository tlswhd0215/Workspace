#include <stdio.h>
#define SEC_PER_HOUR 3600
#define SEC_PER_MIN 60
int main()
{
	int hour, min, sec, wsec;
	printf("시간을 차례로 입력하세요(시,분,초) : ");
	scanf(" %d %d %d", &hour, &min, &sec);
	wsec = SEC_PER_HOUR * hour + SEC_PER_MIN * min + sec;
	printf("%d시간 %d분 %d초는 총 %d초입니다.\n", hour, min, sec, wsec);
	printf("----------------------------------------------------------------------\n");
	printf("환산할 초를 입력하세요 : ");
	scanf(" %d", &wsec);
	printf(" %d는 %d시간 %d분 %d초 입니다.", wsec, wsec / SEC_PER_HOUR, (wsec%SEC_PER_HOUR) / SEC_PER_MIN, (wsec%SEC_PER_HOUR) % SEC_PER_MIN);

	return 0;

}