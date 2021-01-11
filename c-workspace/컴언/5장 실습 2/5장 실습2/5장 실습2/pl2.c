#include <stdio.h>
int main()
{
	int num, i=1, n;
	printf("자연수 입력");
	scanf(" %d", &num);

	while (10 > num > 0)
	{
		num = num / 10;
		i++;
	}

	
}