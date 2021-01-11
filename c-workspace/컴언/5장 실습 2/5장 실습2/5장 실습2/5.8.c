#include <stdio.h>
int main()
{
	int pri, i;
	double inter = 0, sum = 0, all, rate;
	printf("원금 : ");
	scanf(" %d", &pri);
	printf("연이율(%) : ");
	scanf(" %lf", &rate);
	
	all = pri;
	for (i = 1; i <= 10; i++)
	{	
		inter = all * rate / 100;	
		sum += inter;
		all = sum + pri;
	
		printf("%2d년째 이자 : %.2f, ", i, inter);
		printf("원리합계 : %.2f", all);
		printf(" (누적 이자 : %.2f)\n", sum);
		
	}
	return 0;
}