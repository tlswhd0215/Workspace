#include <iostream>
using namespace std;
int main() {
	int a, b;
	double c;
	scanf(" %d %d", &a, &b);

	c = 100.0 * b / (double)(a + b);
	printf("%.2lf", c);
}