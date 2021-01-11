#include <stdio.h>
int main()
{
	int a;
	printf("input value : ");
	scanf(" %d", &a);
	if (a > 0)
		printf("+");
	else if (a == 0)
		printf("zero");
	else
		if (a < 0)
			printf("-");
	return 0;
}