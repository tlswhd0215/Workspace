#include <stdio.h>
int round(double num);
int main()
{
	double num;
	

	while (1)
	{
		printf("�Ǽ��� �Է��ϼ��� (0.0 �Է½� ����) : ");
	    scanf(" %lf", &num);

		if (num == 0.0)
			break;

		printf("%f�� �ݿø� ��� = %d\n", num, round(num));
		
	}
	return 0;
}
int round(double num)
{
	int a;
	if (num >= 0)
		a = (num + 0.5);
	else
		a = (num - 0.5);
	return a;
}