#include <stdio.h>
int main()
{
	int x1, x2;
	char op;
	printf("�ǿ����� 1 �Է� : ");
	scanf(" %d", &x1);
	printf("������ �Է� : ");
	scanf(" %c", &op);
	printf("�ǿ����� 2 �Է� : ");
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