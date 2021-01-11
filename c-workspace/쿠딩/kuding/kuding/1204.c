#include <stdio.h>
int main()
{
	int i;
	char arr[10] = {NULL};
	scanf("%s", arr);
	for (i = 0; i < 10; i++)
	{
		switch (arr[i])
		{
		case'A':
			arr[i] = 0;
			break;
		case'B':
			arr[i] = 1;
			break;
		case'C':
			arr[i] = 2;
			break;
		case'D':
			arr[i] = 3;
			break;
		case'E':
			arr[i] = 4;
			break;
		case'a':
			arr[i] = 5;
			break;
		case'b':
			arr[i] = 6;
			break;
		case'c':
			arr[i] = 7;
			break;
		case'd':
			arr[i] = 8;
			break;
		case'e':
			arr[i] = 9;
			break;
		case NULL:
			break;
		}
		
	}
	for (i = 9; i >= 0; i--)
	{
			printf("%d", arr[i]);
	}
	
	return 0;
}