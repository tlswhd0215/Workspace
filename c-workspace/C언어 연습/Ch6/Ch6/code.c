#include <stdio.h>
void print_star(int length,int height)
{
	int i,j;
	for (j = 0; j < height; j++)
	{
		for (i = 0; i < length; i++)
		{
			printf("*");
		}
		printf("\n");
	}
}
int main()
{
	int length, height;
	printf("���� �Է� : ");
	scanf(" %d", &length);
	printf("���� �Է� : ");
	scanf(" %d", &height);
	print_star(length, height);
	return 0;
}