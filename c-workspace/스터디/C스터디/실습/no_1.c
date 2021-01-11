#include <stdio.h>
int main() {
	int weight, height;
	double energy;
	printf("질량(kg)? ");
	scanf(" %d", &weight);
	printf("높이(m)? ");
	scanf(" %d", &height);

	energy = 9.8*weight*height;
	printf("위치에너지: %g J", energy);//%g는 0을 없앤 상태로 출력

	return 0;
}