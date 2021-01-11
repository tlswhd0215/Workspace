#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NO 6

int selectMenu();
void setSeed(int menu);
void generateLotto(int array[], int size);
void sortArray(int array[], int size);
void displayArray(int array[], int size);
int isNew(const int array[], int currentRand, int cPosition);

int main()
{
	int menu;
	int lotto[NO];

	printf("*************************************\n");
	printf("*    �ζ� ��ȣ ������    *\n");
	printf("*************************************\n");
	while (1)
	{
		menu = selectMenu();

		if (menu == 3)
			break;

		setSeed(menu);
		generateLotto(lotto, NO);
		displayArray(lotto, NO);
	}
	printf("���α׷��� �����մϴ� \n");

	return 0;
}
int selectMenu()
{
	int menu;
	while (1) 
	{
		printf("------------------\n");
		printf("1. �ڵ�����\n2. seed ����\n3. ����\n");
		printf("------------------\n");
		printf("==> �޴� ���� : ");
		scanf("%d", &menu);
		if (menu != 1 && menu != 2 && menu != 3)
		{
			printf("�Է¿���!! 1~3�߿� �����ϼ���\n");
		}
		else
			break;
	}
	return menu;
}
void setSeed(int menu)
{
	unsigned int seed;
	switch (menu)
	{
	case 1:
		srand((unsigned int)time(NULL));
		break;
	case 2:
		printf("seed �� ���� : ");
		scanf("%d", &seed);
		srand(seed);
		break;
	}
}
void generateLotto(int array[], int size)
{
	int re;
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 45+1;
		re = isNew(array, array[i], i);
		if (re == 1)
		{
			i--;
			continue;
		}
	}
}
void sortArray(int array[], int size)
{
	int index, temp;
	for (int i = 0; i < size-1; i++)
	{
		index = i;
		for (int j = i+1 ; j < size; j++)
		{
			if (array[index] > array[j])
				index = j;
		}
		if (i != index)
		{
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
		}
	}
}
void displayArray(int array[], int size)
{
	sortArray(array, size);
	printf("----------------------------\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n----------------------------\n");
}
int isNew(const int array[], int currentRand, int cPosition)
{
	int count = 0;
	for (int i = 0; i < cPosition; i++)
	{
		if (array[i] == currentRand)
			count++;
	}
	if (count == 0)
		return 0;
	else
		return 1;
}