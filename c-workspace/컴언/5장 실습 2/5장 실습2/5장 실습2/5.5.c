#include <stdio.h>
int main()
{
	int num, sum = 0, odd = 0, even = 0, i;
	printf("���� ���� �Է� : ");
	scanf(" %d", &num);

	for (i = 1, sum = 0; i <= num; i++)
		sum += i;
	printf("1���� %d������ �� : %d\n", num, sum);

	i = 0;
	while (i <= num)
	{
		even += i;
		i += 2;
	}
	printf("1���� %d������ ¦���� �� : %d\n", num, even);


	i = 1;
	do {
		odd += i;
		i += 2;
	}
	while (i <= +num);
	printf("1���� %d������ Ȧ���� �� : %d\n", num, odd);
	return 0;
}