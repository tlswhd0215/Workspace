#include <stdio.h>
#include <string.h>
int main()
{
	char str[80];
	int len;
	gets(str);
	len = strlen(str);

	for (int i=0; i < len; i++)
	{
		if ('A' <= str[i]&&str[i]<='Z')
		{
			str[i] += 32;
		}
	}
	printf("%s", str);

	return 0;
}