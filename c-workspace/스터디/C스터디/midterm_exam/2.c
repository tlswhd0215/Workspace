#include <stdio.h>
int main() {
	int a = 5;
	do {
		switch (a%3)
		{
		case 0:
			printf("%d\n", ++a / 2);
		case 1:
			printf("%d\n", a + 7);
			break;
		case 2:
			printf("%d\n", a++*2);
		}
		a /= 2;
	} while (a > 0);
}