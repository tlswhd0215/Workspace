#include <stdio.h>

int main() {
	int n1, n2, n3,min;

	printf("���� 3�� �Է� >> ");
	scanf(" %d %d %d", &n1, &n2, &n3);

	min = ((n1 > n2 ? n2 : n1) > n3 ? n3 : (n1 > n2 ? n2 : n1));

	printf("���� ���� ���� = %d\n", min);
}