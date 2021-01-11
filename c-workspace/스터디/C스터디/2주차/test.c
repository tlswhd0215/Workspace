#include <stdio.h>
#include <math.h>

int main()
{
	int a, b;
	double c;

	printf("밑변? ");
	scanf(" %d", &a);
	printf("높이? ");
	scanf(" %d", &b);

	c = a * a + b * b; //이 부분이 문제인걸 아는데 어떻게 해결해야되는지 모르겠어요,,,,,

	printf("빗변의 길이: %lf", sqrt(c));

}