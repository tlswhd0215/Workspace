#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c, D;
	double midx;
	
	printf("2차방정식의 a, b, c를 입력");
	scanf(" %d %d %d", &a, &b, &c);
    D = b * b - (4 * a*c);
	midx = -b / 2 / a;
	if (D < 0)
		printf("입력하신 2차 방정식은 허근을 가집니다.");
	else if (D == 0)
		printf("입력하신 2차 방정식은 중근 x1=x2= %f을 가집니다.",midx);
	else if (D > 0)
		printf("입력하신 2차 방정식은 두 근 x1 = %f, x2 = %f을 가집니다.", (-b + sqrt(D)) / 2 / a, (-b + sqrt(D) / 2 / a));
	else if (a == 0)
		printf("a=0이면 2차방정식이 아닙니다.");
	return 0;


}