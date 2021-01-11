#include <stdio.h>
#define PI 3.14159265
int main()
{
	int h, a;
	printf("헬멧의 높이(h)와 base반지름(a) 입력\n");
	printf("헬멧의 높이 : ");
	scanf(" %d", &h);
	printf("base의 반지름 : ");
	scanf(" %d", &a);
	printf("헬멧의 체적 : %f\n", PI / 6 * h*(3 * a*a + h * h));
	printf("헬멧의 표면적 : %f", 2.0 * PI*h*(h / 3.0 + (PI / 6 * h*(3.0 * a*a + h * h)) / (PI * h * h)));
	return 0;
}
