#include <stdio.h>
#define MAX_STD 5
struct student {
	char name[20];
	int kor, eng, math;
	double average;
};
int main(void)
{
	struct student std[MAX_STD];
	int i = 0;
	double total_ave = 0;
	printf("%d 명의 학생 정보를 입력하세요.", MAX_STD);
	while(getchar()!="\n"&&i<MAX_STD)
	{
		printf("이름: ");
		gets(std[i].name);
		printf("국어, 영어, 수학 점수: ");
		scanf(" %d %d %d", &std[i].kor, &std[i].eng, &std[i].math);
		std[i].average = (std[i].kor + std[i].eng + std[i].math)/3.0;
		total_ave += std[i].average;
		i++;
	}
	total_ave /= MAX_STD;
	printf("\n이름 \t국어 영어 수학 평균\n");
	for (i = 0; i < MAX_STD; i++)
	{
		printf("%s\t%4d %4d %4d %4.2f\n", std[i].name,std[i].kor, std[i].eng, std[i].math, std[i].average);
	}
	printf("전체 평균 : %6.2f\n", total_ave);
	return 0;
}