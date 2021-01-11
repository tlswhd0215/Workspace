#include <stdio.h>
#define SIZE 80

int my_strlen(const char* p);
void my_strcpy(char* p1, const char* p2);
int my_strcmp(const char* p1, const char* p2);
void makeLower(char p[]);
void makeReverse(char p[]);
void strSwap(char* p1, char* p2);
void swap(char* a, char* b);
int main() {
	char str1[SIZE], str2[SIZE], str3[SIZE];

	printf("���ڿ�(str1) �Է�: ");
	gets_s(str1, SIZE);
	printf("\nstr1�� ���� : %d\n", my_strlen(str1));

	my_strcpy(str2, str1);
	makeLower(str2);
	printf("\nstr1�� �ҹ��ڷ� ��ȯ = %s\n", str2);

	my_strcpy(str3, str1);
	makeReverse(str3);
	printf("\nstr1�� ���� = %s\n", str3);

	if (my_strcmp(str1, str2))
		printf("\n%s == %s\n", str1, str2);
	if (!my_strcmp("abc", "abcd"))
		printf("\n\"abc\" != \"abcd\"\n\n");

	my_strcpy(str3, "C is fun");
	printf("------ strSwap() �Լ� ȣ�� ��---------\n");
	printf("str1 = %s\nstr3 = %s\n", str1, str3);
	strSwap(str1, str3);
	printf("------ strSwap() �Լ� ȣ�� ��---------\n");
	printf("str1 = %s\nstr3 = %s\n", str1, str3);
	return 0;
}
int my_strlen(const char* p) {//���� �迭, ���ڿ� ����� ���޹޾� ���ڿ��� ���� ��ȯ 
	int cnt;
	for (cnt = 0; p[cnt]; cnt++);
	return cnt;
}

void my_strcpy(char* p1, const char* p2) {
	int i;
	for (i = 0; p2[i]; i++) {
		p1[i] = p2[i];
	}
	p1[my_strlen(p1)] = '\n';
}

int my_strcmp(const char* p1, const char* p2) {
	int cpr = 1;

	for (int i = 0; p1[i] || p2[i]; i++) {
		if (!(p1[i] == p2[i])) {//p1�� p2�� ���� �ٸ��� cpr���� �� break
			cpr = 0;
			break;
		}
	}
	return cpr;
}

void makeLower(char p[]) {//���ڹ迭�� ���޹޾� �ҹ��ڷ� ��ȯ���ִ� �Լ�
	do {
		if ('A' <= *p && *p <= 'Z')
			*p += 32;

	} while (p++!=NULL);
}

void makeReverse(char p[]) {//���ڹ迭�� ���޹޾� ������ ��ȯ���ִ� �Լ�
	int num = (my_strlen(p) + 1) / 2;

	for (int i = 0; i < num; i++) {
		swap(&p[i], &p[2 * num - i]);
	}
}

void strSwap(char* p1, char* p2) {//���޹��� �� ���ڿ��� ������ ���� ��ȯ

	for (int i = 0; (p1 + i) || (p2 + i); i++) {
		swap((p1 + i), (p2 + i));
	}
}

void swap(char* a, char* b) {//�� ������ ������ ��ȯ�ϴ� �Լ�
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}