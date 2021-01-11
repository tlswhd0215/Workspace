#include <stdio.h>
int main()
{
	int temp;
	printf("화씨온도를 입력하세요 : ");
	scanf("%d", &temp);
	printf("섭씨온도는 %d도 입니다.", (temp - 32) * 5 / 9);
	return 0;
}