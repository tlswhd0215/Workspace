#include <stdio.h>
int main()
{
	int A, B;
	printf("�ð� �Է� : ");
	scanf(" %d", &A);
	printf("�� �Է� : ");
	scanf(" %d", &B);
	if (A == 12)
		A = 0;
	if (A * 30 + B * 0.5 > B * 6)
	{
		if(A * 30 + B * 0.5 - B * 6>180)
			printf("%f ��", A * 30 + B * 0.5 - B * 6-180);
		else
			printf("%f ��", A * 30 + B * 0.5 - B * 6);
	}
	else if (A * 30 + B * 0.5 == B * 6)
		printf("0 ��");
	else if (A * 30 + B * 0.5 < B * 6)
	{
		if(B * 6 - A * 30 + B * 0.5>180)
			printf("%f ��", B * 6 - A * 30 - B * 0.5-180);
		else
			printf("%f ��", B * 6 - A * 30 - B * 0.5);
	}
	return 0;
}