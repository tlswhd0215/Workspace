#include <stdio.h>
int main() {
	int num1, num2;
	printf("Input Interger>>");
	scanf(" %d %d", &num1,&num2);

	printf("\nNum1 AND Num2\t %d & %d = %d\n", num1, num2, num1&num2);
	printf("Num1 OR Num2\t %d | %d = %d\n", num1, num2, num1|num2);
	printf("Num1 XOR Num2\t %d ^ %d = %d\n", num1, num2, num1^num2);
	printf("NOT Num1\t ~%d = %d\n", num1,~num1);

}