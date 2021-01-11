#include <stdio.h>
int main() {
	int i, sum = 0;
	for (i = 0; i <= 5; i++)
	{
		if (i % 3)
			sum += i++;
	}
	printf("%d %d\n", i, sum);
}