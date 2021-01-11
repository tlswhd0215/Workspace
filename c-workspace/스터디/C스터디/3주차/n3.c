#include <stdio.h>

int main() {
	char opt;
	double area;

	printf("³ĞÀÌ? ");
	scanf(" %lf %c", &area, &opt);

	if (opt == 'p')
		printf("%.2f Æò == %.2f Á¦°ö¹ÌÅÍ\n", area, area*3.305785);
	if (opt == 'm')
		printf("%.2f Á¦°ö¹ÌÅÍ == %.2f Æò\n", area, area*0.3025);
}