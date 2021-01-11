#include <stdio.h>
int main() {
	int op1, op2;
	char op;
	for (;;)
	{
		printf("¼ö½Ä? ");
		scanf(" %d %c %d", &op1, &op, &op2);
		switch (op) {
		case '+':
			printf("%d %c %d = %d\n", op1, op, op2, op1 + op2);
			break;
		case '-':
			printf("%d %c %d = %d\n", op1, op, op2, op1 - op2);
			break;
		case '*':
			printf("%d %c %d = %d\n", op1, op, op2, op1 * op2);
			break;
		case '/':
			printf("%d %c %d = %.2f\n", op1, op, op2, op1 / (double)op2);
			break;
		default:
			return 0;
		}
	}
	return 0;
}