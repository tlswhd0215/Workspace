#include <stdio.h>
int main()
{
	int no, count;
	printf("���� �Է��ϼ��� : ");
	scanf(" %d", &no);
	printf("shift �ϰ��� �ϴ� �� : ");
	scanf(" %d", &count);
	printf("��� : %d", no >> count);

	return 0;
}