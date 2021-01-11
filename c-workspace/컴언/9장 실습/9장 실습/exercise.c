#include <stdio.h>
int Gets_GCD_LCM(int a, int b, int*gcd, int*lcm)
{
	int i;
	for (i = 2; i < (a > b ? b : a); i++)
	{
		if (a%i == 0 && b%i == 0)
		{
			*gcd = i;
		}
	}
	*lcm = a * b / *gcd;
}