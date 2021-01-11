#include <stdio.h>
#include <time.h>
#define SIZE 10//��ȣ��� ����  

void rand_arr(int*a, int size);//�������� ���� �����ϴ� �Լ�
void selection_sort_arr(int*a, int size);//���������Լ�

int main()
{
	int i;
	int arr[SIZE] = { 0 };//�迭 ����
	rand_arr(arr, SIZE);
	printf("�迭�� ���� : ");//�迭�� �ʱ� ���� ���
	for (i = 0; i < SIZE; i++)
	{
		printf(" %d", arr[i]);
	}
	printf("\n");
	selection_sort_arr(arr, SIZE);

	return 0;
}
void rand_arr(int*a, int size)//�ߺ����� ���� �迭 ����
{
	int i, n;
	srand((unsigned int)time(NULL));//����ø��� �ٸ� �迭�� �Է�
	for (i = 0; i < size; i++)
	{
		a[i] = rand() % 90 + 10;//10~99�� �� �߿��� �������� ����
		for (n = 0; n < i; n++)
		{
			if (a[i] == a[n])//�ߺ��� ���� �ԷµǾ��� ��� �ٽ� ����
			{
				i--;
				break;
			}
		}
	}
}
void selection_sort_arr(int*a, int size)//��������
{
	int i, j, temp, n;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
			if (a[i] > a[j])//���õ� �迭�� ���� ���� ������ Ŭ �� �ڸ��� �ٲ۴�
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		printf("%dȸ : ", i + 1);//������ ���
		for (n = 0; n < size; n++)
			printf(" %d", a[n]);
		printf("\n");
	}
}