#include <stdio.h>
int main()
{
	int kor, eng, mat;
	printf("국어 : ");
	scanf(" %d", &kor);
	printf("영어 : ");
	scanf(" %d", &eng);
	printf("수학 : ");
	scanf(" %d", &mat);
	printf("\n평균 : %.1f", (double)(kor + eng + mat) / 3);
	return 0;
}