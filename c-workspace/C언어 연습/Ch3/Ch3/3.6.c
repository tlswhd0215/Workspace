#include <stdio.h>
int main()
{
	int no, count;
	printf("정수 입력 : ");
	scanf(" %d %d", &no, &count);
	printf("%d과 %d의 합은 %d입니다.", no, count, no + count);
	return 0;
}