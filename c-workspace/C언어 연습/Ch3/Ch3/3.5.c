#include <stdio.h>
int main()
{
	double no, in, out;
	//double no = 1.34, in = -2.5, out = 512.3;
	printf("실수 3개 입력\n");
	printf("input no : ");
	scanf(" %lf", &no);
	printf("input in : ");
	scanf(" %lf", &in);
	printf("input out : ");
	scanf(" %lf", &out);
	printf("%5.2f%-6.1f%06.0f", no, in, out);
	return 0;
}