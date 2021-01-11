#include <stdio.h>
int main()
{
	int arr[10] = { 23,43,-34,23,-124,22,2,-9,13,21 };
	int val;
	printf("input value(배열의 값 중 하나): ");
	scanf(" %d", &val);
	int i = 0, count = 0;
	while (i < 10)
	{
		if (arr[i] == val)
		{
			printf("%d에 %d값이 위치함\n", i+1, val);
			count++;
		}
		i++;
	}
	if (count == 0)
		printf("배열에 %d값이 없습니다.", val);

	return 0;

}