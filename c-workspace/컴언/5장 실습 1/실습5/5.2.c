#include <stdio.h>
int main()
{
	double temp;
	char op;
	printf("온도와 온도 단위 입력 : ");
	scanf(" %lf %c", &temp, &op);
	switch (op)
	{
	case 'c':
	case 'C':
		printf("%.2f F", temp*1.8 + 32);
		break;
	case 'f':
	case 'F':
		printf("%.2f C",(temp-32)/1.8);
		break;
	default:
			printf("Error");
	}
	return 0;
}