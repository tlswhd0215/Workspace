#include <stdio.h>
#include <math.h>
int strToInt(char *str);
int main()
{
	char *pstr, str[80];

	printf("Input string: ");
	gets(str);
	pstr = str;
	printf("Ãâ·Â: %4d\n", strToInt(str) * 2);
	return 0;
}
int strToInt(char *str)
{
	int i = 0, len = 0, sum = 0,temp;

	while (str[i] != NULL)
	{
		len++;
		i++;
	}
	for (i = 0; i < len; i++)
	{
		temp = str[i] - 48;
		if (str[0] == '-')
		{
			if (i == 0)
				continue;
		}
		sum += temp * pow(10, len - 1 - i);
	}if (str[0] == '-')
		return sum * (-1);
	else
		return sum;
}