#include <stdio.h>
int main() {
	int i;
	for (i = 0; i < 20;) {
		if (i % 2 == 0)
			i++;
		else
		{
			if (i % 3 == 0) {
				i *= 2;
				continue;
			}
			i *= 3;
		}
		printf("%d ", i);
	}
}