#include <stdio.h>
#define PT 3.30579//�ɺ��� ��� (#define �̿�)
int main() {
	const double ptm= 3.30579;//�ɺ��� ���(const)
	double aptm,aptp;
	printf("����Ʈ�� ����(��������)? ");
	scanf(" %lf", &aptm);
	aptp = aptm / ptm;
	printf("%.2f �������� = %.2f ��\n", aptm, aptp);
}