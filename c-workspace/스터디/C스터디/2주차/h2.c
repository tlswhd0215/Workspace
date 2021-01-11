#include <stdio.h>
int main() {
	int num;
	printf("Input Integer >>");
	scanf(" %d", &num);

	num = ~num + 1;

	printf("Negative : %d", num);
}