#include <stdio.h>
#define MAX 12
int main()
{
	int dig[MAX] = { 0 }, sum = 0;
	printf("Please enter the first eleven UPC digits, seperated by white space: \n");
	for (int i = 0; i < MAX-1; i++)
	{
		scanf("%1d", &dig[i]);
		printf("%d", dig[i]);
	}
	printf("\n");
	for (int i = 0; i < MAX-1; i += 2)
	{
		sum += dig[i] * 3;
	}
	for (int i = 1; i < MAX-1; i += 2)
	{
		sum += dig[i];
	}
	dig[MAX-1] = (10 - sum % 10) % 10;

	printf("The check digit is %d \n", dig[MAX-1]);
	return 0;


}