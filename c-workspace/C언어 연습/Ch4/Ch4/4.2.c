#include <stdio.h>
int main()
{
	int n = 100;//���� ����
	printf("%d\n", ++n);//���� n�� ���� ���� 1��ŭ ���� n=101
	printf("%d\n", n++);//���� n�� ����� �� 1��ŭ ���� n=102 
	printf("%d\n", n + 1);//n=102�� 1�� ���� ���� ���
	printf("%d\n", n);//n�� ���� ���

	return 0;
}


/*mian()
{
	int n = 100;
	printf("%d\n", ++n);
	printf("%d\n", n++);
	printf("%d\n", n + 1);
	printf("%d\n", n);
}*/