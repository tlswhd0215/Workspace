#include <stdio.h>
int main()
{
	int month, fee;
	printf("몇 월 : ");
	scanf(" %d", &month);
	fee = (((month == 6) || (month == 7) || (month == 8)) ? 70000 : 35000);
	printf("입장료 : %d\n", fee);
	return 0;


}