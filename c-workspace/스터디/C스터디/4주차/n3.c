#include<stdio.h>

int main() {
	int min, sum;
	printf("���� �ð��� �ִ� 24�ð�(1440��)�� ���� �� �����ϴ�\n");
	while (1) {
		printf("�����ð� (��)? ");
		scanf(" %d", &min);
		if (min == 0)
			break;
		if (min <= 30)
			sum = 2000;
		else
			sum = 2000 + ((min - 31) / 10 + 1) * 1000;
		if (sum > 25000)
			sum = 25000;

		printf("���� ���: %d��\n", sum);
	}
}