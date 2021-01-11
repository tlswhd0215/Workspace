#include <stdio.h>
int main()
{
	int i = 0, j;
	char arr[1000] = {NULL};
	scanf("%s", arr);

	for(i=0;i<1000;i++)
	{
		if (arr[i] == NULL)
			break;
		if (arr[i] == 'A' || arr[i] == 'B')
		{
			printf("A.B");
		}
		else
			printf("%c", arr[i]);
	}
	return 0;
}