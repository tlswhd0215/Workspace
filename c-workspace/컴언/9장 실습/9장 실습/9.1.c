#include <stdio.h>
#include <string.h>
int main()
{
	char str[80], reversed_str[80];
	char temp;
	int i, len;

	printf("문자열 입력: ");
	gets(str);
	printf("\nstr: %s\n", str);

	i = 0;
	len = 0;
	while (str[i] != NULL)
	{
		len++;
		i++;
	}
	for (i = 0; i < len; i++)
	{
		reversed_str[len - i - 1] = str[i];
	}
	reversed_str[len] = NULL;
	printf("reversed_str: %s\n", reversed_str);

	for (i = 0; i < len/2; i++)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	printf("변환된 str: %s\n", str);

	return 0;
}  