#include <stdio.h>
int main()
{
	char ch;
	int count=0;
	while(ch = getchar())
	{
		++count;
		putchar(ch);
	}
	printf("%d\n", count);
	return 0;
}