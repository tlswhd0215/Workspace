#include <stdio.h>

int main() {
	char opt;
	double area;

	printf("����? ");
	scanf(" %lf %c", &area, &opt);

	if (opt == 'p')
		printf("%.2f �� == %.2f ��������\n", area, area*3.305785);
	if (opt == 'm')
		printf("%.2f �������� == %.2f ��\n", area, area*0.3025);
}