#include <stdio.h>

int main() {
	int fp, sp, ep;
	double sale;

	printf("��ǰ�� ����? ");
	scanf(" %d", &fp);

	printf("������(%%)? ");
	scanf(" %lf", &sale);

	sale /= 100;
	ep = fp * sale;
	sp = fp - ep;
	printf("���ΰ�: %d�� (%d�� ����)\n", sp, ep);
}