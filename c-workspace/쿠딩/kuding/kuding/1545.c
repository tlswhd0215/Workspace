#include <stdio.h>
#include <stdlib.h>
void swap(int x, int y);
int main()
{
	int a[9], b[9], n1, n2;
	char x1, x2, op[4];
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &b[i]);
	}
	scanf("%c%d %s %c%d", &x1, &n1, op, &x2, &n2);

	switch (x1)
	{
	case 'A':
	case 'a':
		if (x2 == 'A' || x2 == 'a')
			swap(a[n1], a[n2]);
		else
			swap(a[n1], b[n2]);
		break;
	case 'B':
	case 'b':
		if (x2 == 'A' || x2 == 'a')
			swap(b[n1], a[n2]);
		else
			swap(b[n1], b[n2]);
		break;
	}

	for (int i = 0; i < 9; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < 9; i++)
	{
		printf("%d ",b[i]);
	}
	return 0;
}
void swap(int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}