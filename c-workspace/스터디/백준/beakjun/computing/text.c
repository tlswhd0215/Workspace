#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#define SIZE 120
void test(const char* a) {

}
int main() {
	test("Hello");
	char str1[SIZE];
	char* initial;

	do {
		printf("���� �̸�? ");
		gets_s(str1, SIZE);

		printf("�̴ϼ�: ");
		initial = strtok(str1, " ");

		while (initial != NULL) {
			printf("%c", toupper(initial[0]));
			initial = strtok(NULL, " ");
		}
		printf("\n");
	} while (str1[0] != '\0');
}