#include <stdio.h>
int round(double num);
int main()
{
	double num;
	

	while (1)
	{
		printf("실수를 입력하세요 (0.0 입력시 종료) : ");
	    scanf(" %lf", &num);

		if (num == 0.0)
			break;

		printf("%f의 반올림 결과 = %d\n", num, round(num));
		
	}
	return 0;
}
int round(double num)
{
	int a;
	if (num >= 0)
		a = (num + 0.5);
	else
		a = (num - 0.5);
	return a;
}