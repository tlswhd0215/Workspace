#include <stdio.h>
#define PT 3.30579//심볼릭 상수 (#define 이용)
int main() {
	const double ptm= 3.30579;//심볼릭 상수(const)
	double aptm,aptp;
	printf("아파트의 면적(제곱미터)? ");
	scanf(" %lf", &aptm);
	aptp = aptm / ptm;
	printf("%.2f 제곱미터 = %.2f 평\n", aptm, aptp);
}