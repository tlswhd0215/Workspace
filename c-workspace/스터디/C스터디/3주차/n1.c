#include <stdio.h>

int main() {
	int left, top, right, bottom, x, y;

	printf("���� ������ �� ����� (left, top)? ");
	scanf(" %d %d", &left, &top);

	printf("���� ������ �� �ϴ��� (right,bottom)? ");
	scanf(" %d %d", &right, &bottom);

	printf("���� ��ǥ (x, y)? ");
	scanf(" %d %d", &x, &y);

	if (left < x&&x < right&&top < y&&y < bottom)
		printf("���簢�� ����� ���� ���� ���� ���Դϴ�.\n");
	else
		printf("���簢�� ����� ���� ���� ���� ���Դϴ�.\n");
}