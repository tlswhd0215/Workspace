#include <stdio.h>
int main()
{
	int c, cs, py, wrt, cal, che, exa, sum, i = 0, max = 0, min = 100, j, n;
	printf("�Ϲݹ��� ���� �Է� : ");
	scanf(" %d", &cal);
	printf("�Ϲ�ȭ�� ���� �Է� : ");
	scanf(" %d", &che);
	printf("�Ϲ�ȭ�н��� ���� �Է� : ");
	scanf(" %d", &exa);
	printf("C��� ���� �Է� : ");
	scanf(" %d", &c);
	printf("C��� �ǽ� ���� �Է� : ");
	scanf(" %d", &cs);
	printf("���̽� �Է� : ");
	scanf(" %d", &py);
	printf("�۾��� ���� �Է� : ");
	scanf(" %d", &wrt);
	sum = c + cs + py + wrt + cal + che + exa;
	printf("��� ������ ���� : %d\n", sum);
	printf("��� ���� ��� : %.4f\n", ((sum)/7.0));
	if (cal > max)
		max = cal;
	if (che > max)
		max = che;
	if (exa > max)
		max = exa;
	if (c > max)
		max = c;
	if (cs > max)
		max = cs;
	if (py > max)
		max = py;
	if (wrt > max)
		max = wrt;
	printf("���� ���� ������ ���� : %d\n",max);
	if (cal < min)
		min = cal;
	if (che < min)
		min = che;
	if (exa< min)
		min = exa;
	if (c < min)
		min = c;
	if (cs < min)
		min = cs;
	if (py < min)
		min = py;
	if (wrt < min)
		min = wrt;
	printf("���� ���� ������ �̸� : %d\n",min);
	if (che < 50)
		i++;
	if (c < 50)
		i++;
	if (cs < 50)
		i++;
	if (py < 50)
		i++;
	if (wrt < 50)
		i++;
	if (cal < 50)
		i++;
	if (exa < 50)
		i++;
	if (i >= 4)
		printf("�����б�");
	else
		printf("�����б�");
}