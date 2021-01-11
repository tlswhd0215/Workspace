#include <stdio.h>
int main()
{
	int no, count;
	printf("값을 입력하세요 : ");
	scanf(" %d", &no);
	printf("shift 하고자 하는 값 : ");
	scanf(" %d", &count);
	printf("결과 : %d", no >> count);

	return 0;
}