#include <iostream>
#include <string>

using namespace std;
void rotateLeft(string *str, int move);
void rotateRight(string *str, int move);
int main() {
	string str;
	char choice;
	int move;

	cout << "���ڿ��� �Է��ϼ���(�ѱ� �ȵ�) : ";
	cin >> str;
	cout << "------------------------------------" << endl;
	cout << "Original Array: " << str << endl;
	cout << "------------------------------------" << endl;

	while (true) {
		do {
			cout << "ȸ�� ���� ����(r: ���� ȸ��, l: ����ȭ��, q: ����): ";
			cin >> choice;
			if (choice == 'r' || choice == 'l' || choice == 'q')break;
			cout << "�Է� ����! �޴��� �ٽ� �����ϼ���" << endl;
		} while (true);
		if (choice == 'q')break;
		cout << "ȸ����(���) �Է�: ";
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