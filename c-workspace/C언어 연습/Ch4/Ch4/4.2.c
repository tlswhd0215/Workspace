#include <stdio.h>
int main()
{
	int n = 100;//변수 선언
	printf("%d\n", ++n);//변수 n의 값을 먼저 1만큼 증가 n=101
	printf("%d\n", n++);//변수 n을 출력한 후 1만큼 증가 n=102 
	printf("%d\n", n + 1);//n=102에 1을 더한 값을 출력
	printf("%d\n", n);//n의 값을 출력

	return 0;
}


/*mian()
{
	int n = 100;
	printf("%d\n", ++n);
	printf("%d\n", n++);
	printf("%d\n", n + 1);
	printf("%d\n", n);
}*/