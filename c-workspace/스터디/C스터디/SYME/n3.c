#include <stdio.h>
int Conv(int year, int month, int day) {
	int y, m, d;
	y = year << 16;
	m = month << 8;
	d = day;
	return y + m + d;
}
int IsLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}
int IsValid(int year, int month, int day) {
	if (day < 1||month<1||month>12||year<1)
		return 0;
	if (month == 2)
	{
		if (IsLeapYear(year))
		{
			if (day <= 29)
				return 1;
			else
				return 0;
		}
		else {
			if (day <= 28)
				return 1;
			else
				return 0;
		}
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day <= 31)
			return 1;
		else
			return 0;
	}
	else {
		if (day <= 30)
			return 1;
		else
			return 0;
	}

}
int main() {
	int year, month, day;
	while (1) {
		printf("������� �Է��Ͻÿ�. ");
		scanf(" %d %d %d", &year, &month, &day);

		if (!IsValid(year, month, day)) {
			printf("�߸��� ��¥�Դϴ�.\n");
			break;
		}
		printf("%d�� %d�� %d���� %#x�Դϴ�\n", year, month, day, Conv(year, month, day));
	}
	return 0;
}