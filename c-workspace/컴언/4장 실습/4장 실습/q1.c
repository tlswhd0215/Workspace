#include <stdio.h>

int main()
{
	double mass, velo;
	printf(" 질량과 속력을 입력\n");
	printf("질량(kg) : ");
	scanf(" %lf", &mass);
	printf("속력(kg) : ");
	scanf(" %lf", &velo);
	printf("운동에너지 : %f J", mass * velo * velo / 2);
	return 0;
}