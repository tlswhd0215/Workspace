#include <stdio.h>
int main()
{
	int num = 0, sum = 0, i = 0;
	while (num != -1)
	{
		printf("정수 입력(종료: -1) : ");
		scanf(" %d", &num);
		sum += num;
		i++;
	}
	printf("입력된 정수의 합 : %d\n", sum + 1);
	printf("입력된 정수의 평균 : %.2f", (double)(sum + 1) / (i - 1));
	return 0;
}