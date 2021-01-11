#include <stdio.h>
int main() {
	int a = 0, b = 2, c = 3;
	printf("1. %d\n", a=--b*c);
	printf("2. %d \n",c<<=a-2==b++);
	printf("3. %d %d\n", c>b?b++:a--,a%b==1);
	printf("4. %d %d %d\n", a, b, c);
}