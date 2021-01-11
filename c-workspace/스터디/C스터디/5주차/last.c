#include <stdio.h>
int is_composite(int n);
int main() {
	int num, factor;
	while (1) {
		printf("1보다 큰 정수 입력(1이하의 수 입력시 종료): ");
		scanf_s("%d", &num);
		if (num<=1) {
			printf("프로그램을 종료합니다\n");
			break;
		}
		printf("%d = ", num);
		while (1) {
			if (!is_composite(num)){	
				printf("%d\n", num);
				break;}
			printf("%d * ", is_composite(num));
			num /= is_composite(num);
		}
	}
}
int is_composite(int n) {
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
			return i;
	}
	return 0;
}
