#include <stdio.h>
int main()
{
	int arr[10] = { 23,43,-34,23,-124,22,2,-9,13,21 };
	int val;
	printf("input value(�迭�� �� �� �ϳ�): ");
	scanf(" %d", &val);
	int i = 0, count = 0;
	while (i < 10)
	{
		if (arr[i] == val)
		{
			printf("%d�� %d���� ��ġ��\n", i+1, val);
			count++;
		}
		i++;
	}
	if (count == 0)
		printf("�迭�� %d���� �����ϴ�.", val);

	return 0;

}