#include <stdio.h>

int main() {
	int n1, n2, n3,min;

	printf("정수 3개 입력 >> ");
	scanf(" %d %d %d", &n1, &n2, &n3);

	min = ((n1 > n2 ? n2 : n1) > n3 ? n3 : (n1 > n2 ? n2 : n1));

	printf("가장 작은 정수 = %d\n", min);
}