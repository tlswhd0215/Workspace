#include<stdio.h>
int Fact(int num)
{
	int sum = 1;
	for (int i = 1; i <= num; i++)
	{
		 sum *= i;
		
	}
	return sum;
}
int main()
{
	int num, result;
	printf("Input Value : ");
	scanf(" %d", &num);
	result = Fact(num);
	printf("%d! : %d", num, result);

	return 0;
}