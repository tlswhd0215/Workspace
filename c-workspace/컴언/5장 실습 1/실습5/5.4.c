#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c, D;
	double midx;
	
	printf("2���������� a, b, c�� �Է�");
	scanf(" %d %d %d", &a, &b, &c);
    D = b * b - (4 * a*c);
	midx = -b / 2 / a;
	if (D < 0)
		printf("�Է��Ͻ� 2�� �������� ����� �����ϴ�.");
	else if (D == 0)
		printf("�Է��Ͻ� 2�� �������� �߱� x1=x2= %f�� �����ϴ�.",midx);
	else if (D > 0)
		printf("�Է��Ͻ� 2�� �������� �� �� x1 = %f, x2 = %f�� �����ϴ�.", (-b + sqrt(D)) / 2 / a, (-b + sqrt(D) / 2 / a));
	else if (a == 0)
		printf("a=0�̸� 2���������� �ƴմϴ�.");
	return 0;


}