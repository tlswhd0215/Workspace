#include <stdio.h>
int main()
{
	int num, i, n = 0;

	printf("���� ���� �Է� : ");
	scanf(" %d", &num);

	for (i = 2; i < num; i++)
	{
		
		if (num%i == 0)
		{
			printf("�Ҽ��� �ƴմϴ�.");
			break;
		}
		n++;
	}
	if (n == num - 2)
		printf("�Ҽ��Դϴ�");
	return 0;
}