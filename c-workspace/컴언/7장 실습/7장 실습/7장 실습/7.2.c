#include <stdio.h>
#define MAX 10
int main()
{
	int num[MAX], a, d,i;
	printf("ù ��° ��? ");
	scanf(" %d", &a);
	printf("����? ");
	scanf(" %d", &d);
	printf("�������� :");
	for (i = 0; i < MAX; i++)
	{
		num[i] = a + d * i;
		printf(" %d", num[i]);
	}
	return 0;
}