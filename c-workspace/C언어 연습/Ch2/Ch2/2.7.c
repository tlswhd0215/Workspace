#include <stdio.h>
int main()
{
	printf("char\t: %d byte\n", sizeof(char));
	printf("short\t: %d byte\n", sizeof(short));
	printf("int\t: %d byte\n", sizeof(int));
	printf("long\t: %d byte\n", sizeof(long));
	printf("float\t: %d byte\n", sizeof(float));
	printf("double\t: %d byte\n", sizeof(double));

	return 0;
}