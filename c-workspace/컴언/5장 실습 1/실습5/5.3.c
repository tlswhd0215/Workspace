#include <stdio.h>
#define BASIC_200kWh 910
#define BASIC_201kWh 1600
#define BASIC_400kWh 7300
#define ELEC_200kWh 93.3
#define ELEC_201kWh 187.9
#define ELEC_400kWh 280.6
int main()
{
	int elec, total, basic, used;
	printf("�� ��뷮 (kWh) : ");
	scanf(" %d", &elec);
	if (elec <= 200)
	{
		printf("�������հ� : %7.f��\n", ELEC_200kWh*elec + BASIC_200kWh);
		printf("-�⺻��� : %10d��\n", BASIC_200kWh);
		printf("-���·���� : %8.f��", ELEC_200kWh*elec);
	}
	else if (elec >= 201 && elec <= 400)
	{
		printf("�������հ� : %7.f��\n", ELEC_200kWh * 200 + ELEC_201kWh * (elec - 200) + BASIC_201kWh);
		printf("-�⺻��� : %10d��\n", BASIC_201kWh);
		printf("-���·���� : %8.f��", ELEC_200kWh*200+ ELEC_201kWh *(elec-200));
	}
	else if (elec>400)
	{
		printf("�������հ� : %7.f��\n", ELEC_200kWh * 200 + ELEC_201kWh * 200 + ELEC_400kWh * (elec - 400) + BASIC_400kWh);
		printf("-�⺻��� : %10d��\n", BASIC_400kWh);
		printf("-���·���� : %8.f��", ELEC_200kWh * 200 + ELEC_201kWh * 200 + ELEC_400kWh * (elec - 400));
	}
	return 0;
}