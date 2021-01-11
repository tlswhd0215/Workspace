#include <stdio.h>
int main()
{
	
	char jun, gun;
quit:
	printf("준호의 가위바위보 입력 : ");
	scanf(" %c", &jun);
	printf("건이의 가위바위보 입력 : ");
	scanf(" %c", &gun);
	if (jun == 's')
		switch (gun)
		{
		case 'r':
			printf("설거지노예 => 준호");
			break;
		case 'p':
			printf("설거지노예 => 건이");
			break;
		case 's':
			goto quit;
			break;
		default:
			printf("Error");
		}
	else if (jun == 'r')
		switch (gun)
		{
		case 'p':
			printf("설거지노예 => 준호");
			break;
		case 's':
			printf("설거지노예 => 건이");
			break;
		case 'r':
			goto quit;
			break;
		default:
			printf("Error");
		}
	else if (jun == 'p')
	{
		switch (gun)
		{
		case 's':
			printf("설거지노예 => 준호");
			break;
		case 'r':
			printf("설거지노예 => 건이");
			break;
		case 'p':
			goto quit;
			break;
		default:
			printf("Error");
		}
	}
	return 0;
}