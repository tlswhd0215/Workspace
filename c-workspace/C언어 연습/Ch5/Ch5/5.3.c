#include <stdio.h>
int main()
{
	int no;
	printf("정수 입력 : ");
	scanf(" %d", &no);
	if (no >= 1 && no <= 10)
		printf("%d\n", no * 2);
	else
		printf("%d", no);
	return 0;
}