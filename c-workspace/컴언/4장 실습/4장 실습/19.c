#include <stdio.h>
int main()
{
	int x = 0xab, y = 0x0f;
	int z;
	z = x ^ y;
	printf("z = %08x\n", z);

	z = ~x | y << 4;
	printf("z = %08x\n", z);
	return 0;
}