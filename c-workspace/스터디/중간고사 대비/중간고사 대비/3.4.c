#include <stdio.h>
int main()
{
	int num, even = 0, odd = 0;
	printf("0�� ���Ե��� ���� �� �Է� : ");
	scanf(" %d", &num);

	while (num>0)
	{
		if ((num % 10) % 2 == 0)
			even++;
		else
			odd++;
		num = (num - num % 10) / 10;
	}
	printf("¦�� %d��\nȦ�� %d��", even, odd);
	return 0;
}