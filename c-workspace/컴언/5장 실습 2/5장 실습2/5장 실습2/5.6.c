#include <stdio.h>
int main()
{
	int num = 0, sum = 0, i = 0;
	while (num != -1)
	{
		printf("���� �Է�(����: -1) : ");
		scanf(" %d", &num);
		sum += num;
		i++;
	}
	printf("�Էµ� ������ �� : %d\n", sum + 1);
	printf("�Էµ� ������ ��� : %.2f", (double)(sum + 1) / (i - 1));
	return 0;
}