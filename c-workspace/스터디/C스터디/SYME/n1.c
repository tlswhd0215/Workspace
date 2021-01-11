#include <stdio.h>
int IsPrime(int num) {
	for (int i = 2; i < num; i++)
	{
		if (num%i==0)
			return 0;
	}
	return 1;
}
int main() {
	int n1, n2;
	int count, temp=0;

	while (1) {
		printf("두 정수를 입력하시오. ");
		scanf(" %d %d", &n1, &n2);
		if (n1 >= n2)
			break;
		count = 0;
		for (int i = n1; i <= n2; i++)
		{
			if (IsPrime(i)) {
				printf("%10d", i);
				temp = i;
				count++;
			}
			if (count % 8 == 0 && temp == i)
				printf("\n");
		}
	}
	return 0;
}