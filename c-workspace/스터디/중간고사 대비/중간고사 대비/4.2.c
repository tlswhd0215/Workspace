#include <stdio.h>
int main()
{
	int x1, x2;
	char op;
	printf("피연산자 1 입력 : ");
	scanf(" %d", &x1);
	printf("연산자 입력 : ");
	scanf(" %c", &op);
	printf("피연산자 2 입력 : ");
	scanf(" %d", &x2);
	switch (op)
	{
	case '+':
		printf("%d",x1+x2);
		break;
	case '-':
		printf("%d", x1 - x2);
		break;
	case '*':
		printf("%d", x1*x2);
		break;
	case '/':
		printf("%f", (double)(x1 / x2));
		break;
	case '%':
		printf("%d", x1%x2);
		break;
	default:
		printf("Error");
	}
	return 0;
}