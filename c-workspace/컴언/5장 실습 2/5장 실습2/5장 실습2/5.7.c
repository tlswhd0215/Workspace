#include <stdio.h>
int main()
{
	int num, qun, i;
	printf("���� �Է� : ");
	scanf(" %d", &num);
	printf("���� �Է� : ");
	scanf(" %d", &qun);

	for (i = 1; i <= qun; i++)
		printf("��� : %d\n", num*i);

	return 0;
		
}