#include <iostream>
#include <cstring>
#define MAX 80
using namespace std;
void rotateLeft(char p[], int move);
void rotateRight(char p[], int move);
int main() {
	char str[MAX];
	char choice;
	int move;

	cout << "문자열을 입력하세요(한글 안됨) : ";
	cin.getline(str, 80, '\n');
	cout << "------------------------------------" << endl;
	cout << "Original Array: " << str << endl;
	cout << "------------------------------------" << endl;

	while (true) {
		do {
			cout << "회전 방향 선택(r: 우측 회전, l: 좌측화전, q: 종료): ";
			cin >> choice;
			if (choice == 'r' || choice == 'l' || choice == 'q')break;
			cout << "입력 오류! 메뉴를 다시 선택하세요" << endl;
		} while (true);
		if (choice == 'q')break;
		cout << "회전량(양수) 입력: ";
		cin >> move;
		int len = strlen(str);
		switch (choice) {
		case'l': for (int i = 0; i < len; i++)
		{
			rotateLeft(str, move);
			cout << str << endl;
		}break;
		case'r':for (int i = 0; i < len; i++)
		{
			rotateRight(str, move);
			cout << str << endl;
		}break;
		}
		return 0;
	}
}
void rotateLeft(char p[], int move) {
	int len = strlen(p);
	if (move%len != 0) {
		move = move % len;
	}
	else
		return;
	if (len - move == 1)
		len++;
	char *tmp = new char[move];
	if (!tmp) {
		cout << "오류가 발생했습니다.";
		exit(1);
	}
	strncpy(tmp, p, move);
	for (int i = move;i<len; i++)
	{
		p[i - move] = p[i];
		p[i] = '\0';
	}
	strncat(p, tmp, move);
	delete[] tmp;
}
void rotateRight(char p[], int move) {
	int len = move % strlen(p);
	if (len == 0) return;

	char * tmp = new char[len];
	if (!tmp) {
		cout << "오류가 발생했습니다.";
		exit(1);
	}

	int size = strlen(p);
	for (int i = 0, j = size - len; i < len; i++, j++) {
		tmp[i] = p[j];
	}

	for (int i = size - len - 1, j = size - 1; i >= 0; i--, j--) {
		p[j] = p[i];
	}

	for (int i = 0; i < len; i++) {
		p[i] = tmp[i];
	}
	delete[] tmp;
}