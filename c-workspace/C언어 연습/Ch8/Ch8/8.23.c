#include <stdio.h>
int main()
{
	int i, j;
	double temp;
	double arr[3][4] = { {5.0,7.0,4.0,3.0},{6.0,2.0,8.0,3.0},{4.0,2.0,8.0,6.0} };
	for (i = 0; i < 3; i++)//ó�� �迭 ���
	{
		for (j = 0; j < 4; j++)
		{
			printf("%.1f\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------\n");
	for (i = 0; i < 3; i++)//�밢�� ������ �� ���� ����
	{			
		temp = arr[i][i];
		for (j = 0; j < 4; j++)
		{
			arr[i][j] = arr[i][j]/temp;
		}
	}
	for (i = 0; i < 3; i++)//���� ���� �迭 ���
	{
		for (j = 0; j < 4; j++)
		{
			printf("%.1f\t", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}