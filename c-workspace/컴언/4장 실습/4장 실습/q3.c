#include <stdio.h>
#define SEC_PER_HOUR 3600
#define SEC_PER_MIN 60
int main()
{
	int hour, min, sec, wsec;
	printf("�ð��� ���ʷ� �Է��ϼ���(��,��,��) : ");
	scanf(" %d %d %d", &hour, &min, &sec);
	wsec = SEC_PER_HOUR * hour + SEC_PER_MIN * min + sec;
	printf("%d�ð� %d�� %d�ʴ� �� %d���Դϴ�.\n", hour, min, sec, wsec);
	printf("----------------------------------------------------------------------\n");
	printf("ȯ���� �ʸ� �Է��ϼ��� : ");
	scanf(" %d", &wsec);
	printf(" %d�� %d�ð� %d�� %d�� �Դϴ�.", wsec, wsec / SEC_PER_HOUR, (wsec%SEC_PER_HOUR) / SEC_PER_MIN, (wsec%SEC_PER_HOUR) % SEC_PER_MIN);

	return 0;

}