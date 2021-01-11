#include <stdio.h>
int a, c = 1;
int big(int a, int b) {
	c = a > b ? a : b;
	return c;
}
int small(int b, int c) {
	a = b > c ? c : b;
	return a;
}
int main() {
	int b = 10, d = 5;
	printf("%d %d %d %d\n", a, b, c, d);
	printf("%d %d %d %d\n", big(a, d), small(b, c), a, c);
}