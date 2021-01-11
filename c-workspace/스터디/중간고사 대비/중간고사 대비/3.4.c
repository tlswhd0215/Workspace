#include <stdio.h>
int main()
{
	int num, even = 0, odd = 0;
	printf("0이 포함되지 않은 수 입력 : ");
	scanf(" %d", &num);

	while (num>0)
	{
		if ((num % 10) % 2 == 0)
			even++;
		else
			odd++;
		num = (num - num % 10) / 10;
	}
	printf("짝수 %d개\n홀수 %d개", even, odd);
	return 0;
}