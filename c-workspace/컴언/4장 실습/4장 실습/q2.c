#include <stdio.h>
int main()
{
	double F;
	printf("È­¾¾¿Âµµ ÀÔ·Â\nÈ­¾¾¿Âµµ(F) : ");
	scanf(" %lf", &F);
	printf("¼·¾¾¿Âµµ : %f C", (F - 32) * 5 / 9);
	return 0;
	
}