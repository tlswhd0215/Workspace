#include <iostream>
#include <string>

using namespace std;
void rotateLeft(string *str, int move);
void rotateRight(string *str, int move);
int main() {
	string str;
	char choice;
	int move;

	cout << "문자열을 입력하세요(한글 안됨) : ";
	cin >> str;
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
		int len = str.length();
		switch (choice) {
		case'l': for (int i = 0; i < len; i++)
		{
			rotateLeft(&str, move);
			cout << str << endl;
		}break;
		case'r':for (int i = 0; i < len; i++)
		{
			rotateRight(&str, move);
			cout << str << endl;
		}break;
		}
		return 0;
	}
}
void rotateLeft(string *str, int move) {
	int len = str->length();
	if (move%len != 0) {
		move = move % len;
	}
	else
		return;
	string first = str->substr(0, move);
	string sub = str->substr(move, len - 1);
	*str = sub + first;
}
void rotateRight(string *str, int move) {
	int len = str->length();
	if (move%len != 0) {
		move = move % len;
	}
	else
		return;
	string first = str->substr(len - move, len);
	string sub = str->substr(0, len - move);
	*str = first + sub;
}