#include <stdio.h>

float add_div(int x, int y, int *z);//float/float의 연산 결과는 float형이므로 리턴형은 float이다 
int main()
{
	int add;//add는 정수의 합이므로 정수형으로 선언해준다
	float div;
	div = add_div(3, 5, &add);
	printf("합 : %d, 나눗셈 : %f\n", add, div);

	return 0;
}
float add_div(int x, int y, int *z)//정수 두 개와 포인터를 전달받음
{
	*z = x + y;//입력받은 포인터가 가리키는 변수에 정수의 합을 대입
	return ((float)x / (float)y);//나눗셈 결과를 리턴
}