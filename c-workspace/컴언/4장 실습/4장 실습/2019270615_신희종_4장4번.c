#include <stdio.h>
#define MIN_PER_DAY 1440
#define MIN_PER_HOUR 60
int main()
{
	double time, wmin;
	int day, hour, min;
    printf("�� �ҿ�ð� �Է� : ");
	scanf(" %lf", &time);
	wmin = time * MIN_PER_HOUR;
	day = wmin / MIN_PER_DAY;
	hour = (wmin - MIN_PER_DAY * day) / MIN_PER_HOUR;
	min = wmin - day * MIN_PER_DAY - hour * MIN_PER_HOUR;
	printf("%d�� %d�ð� %d�� �Դϴ�.", day, hour, min);
	return 0;
}