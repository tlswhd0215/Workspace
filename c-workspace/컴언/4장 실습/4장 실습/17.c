#include <stdio.h>
int main()
{
	int month, fee;
	printf("�� �� : ");
	scanf(" %d", &month);
	fee = (((month == 6) || (month == 7) || (month == 8)) ? 70000 : 35000);
	printf("����� : %d\n", fee);
	return 0;


}