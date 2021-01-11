#include <stdio.h>
int main()
{
	int c, cs, py, wrt, cal, che, exa, sum, i = 0, max = 0, min = 100, j, n;
	printf("일반미적 점수 입력 : ");
	scanf(" %d", &cal);
	printf("일반화학 점수 입력 : ");
	scanf(" %d", &che);
	printf("일반화학실험 점수 입력 : ");
	scanf(" %d", &exa);
	printf("C언어 점수 입력 : ");
	scanf(" %d", &c);
	printf("C언어 실습 점수 입력 : ");
	scanf(" %d", &cs);
	printf("파이썬 입력 : ");
	scanf(" %d", &py);
	printf("글쓰기 점수 입력 : ");
	scanf(" %d", &wrt);
	sum = c + cs + py + wrt + cal + che + exa;
	printf("모든 점수의 총합 : %d\n", sum);
	printf("모든 점수 평균 : %.4f\n", ((sum)/7.0));
	if (cal > max)
		max = cal;
	if (che > max)
		max = che;
	if (exa > max)
		max = exa;
	if (c > max)
		max = c;
	if (cs > max)
		max = cs;
	if (py > max)
		max = py;
	if (wrt > max)
		max = wrt;
	printf("가장 높은 과목의 점수 : %d\n",max);
	if (cal < min)
		min = cal;
	if (che < min)
		min = che;
	if (exa< min)
		min = exa;
	if (c < min)
		min = c;
	if (cs < min)
		min = cs;
	if (py < min)
		min = py;
	if (wrt < min)
		min = wrt;
	printf("가장 낮은 점수의 이름 : %d\n",min);
	if (che < 50)
		i++;
	if (c < 50)
		i++;
	if (cs < 50)
		i++;
	if (py < 50)
		i++;
	if (wrt < 50)
		i++;
	if (cal < 50)
		i++;
	if (exa < 50)
		i++;
	if (i >= 4)
		printf("계절학기");
	else
		printf("다음학기");
}