#include <stdio.h>
int main()
{
	int no;
	printf("���� �Է� : ");
	scanf(" %d", &no);
	if (no >= 1 && no <= 10)
		printf("%d\n", no * 2);
	else
		printf("%d", no);
	return 0;
}