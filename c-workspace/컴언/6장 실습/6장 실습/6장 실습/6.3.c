#include <stdio.h>
int isLeapYear(int year);
int GetFaysOfMonth(int year, int month);
int main()
{
	int year, month;
	printf("�⵵ �Է� : ");
	scanf(" %d", &year);
	printf("�� �Է� : ");
	scanf(" %d", &month);

	printf("%d���� %d���� %d�� ���� �ֽ��ϴ�.", year, month, GetFaysOfMonth(year, month));
	return 0;
}
int isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		return 1;
	}
	else if (year % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int GetFaysOfMonth(int year, int month)
{
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			return 31;
		else if (month == 4 || month == 6 || month == 9 || month == 11)
			return 30;
		else if (month == 2)
			if (isLeapYear(year) == 1)
				return 29;
			else 
				return 28;
	}
	
}
