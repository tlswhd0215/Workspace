#include <stdio.h>
int main() {
	int weight, height;
	double energy;
	printf("����(kg)? ");
	scanf(" %d", &weight);
	printf("����(m)? ");
	scanf(" %d", &height);

	energy = 9.8*weight*height;
	printf("��ġ������: %g J", energy);//%g�� 0�� ���� ���·� ���

	return 0;
}