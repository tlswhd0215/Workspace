#include <stdio.h>
int main()
{
	int kor, eng, mat;
	printf("���� : ");
	scanf(" %d", &kor);
	printf("���� : ");
	scanf(" %d", &eng);
	printf("���� : ");
	scanf(" %d", &mat);
	printf("\n��� : %.1f", (double)(kor + eng + mat) / 3);
	return 0;
}