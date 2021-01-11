#include <stdio.h>
int main()
{
	int num, qun, i;
	printf("정수 입력 : ");
	scanf(" %d", &num);
	printf("개수 입력 : ");
	scanf(" %d", &qun);

	for (i = 1; i <= qun; i++)
		printf("배수 : %d\n", num*i);

	return 0;
		
}