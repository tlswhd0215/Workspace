#include <stdio.h>
int main()
{
	int time;
	printf("�ð��� �Է� : ");
	scanf(" %d", &time);
	if (time <= 12 && time >= 1)
		printf("���� %d��", time);
	else if (time > 12 && time <= 24)
		printf("���� %d��", time - 12);
	else
		printf("�߸��� �Է�");
	return 0;
}