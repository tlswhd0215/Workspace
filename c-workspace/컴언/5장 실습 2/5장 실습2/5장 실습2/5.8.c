#include <stdio.h>
int main()
{
	int pri, i;
	double inter = 0, sum = 0, all, rate;
	printf("���� : ");
	scanf(" %d", &pri);
	printf("������(%) : ");
	scanf(" %lf", &rate);
	
	all = pri;
	for (i = 1; i <= 10; i++)
	{	
		inter = all * rate / 100;	
		sum += inter;
		all = sum + pri;
	
		printf("%2d��° ���� : %.2f, ", i, inter);
		printf("�����հ� : %.2f", all);
		printf(" (���� ���� : %.2f)\n", sum);
		
	}
	return 0;
}