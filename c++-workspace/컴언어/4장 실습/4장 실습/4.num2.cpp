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

	cout << "���ڿ��� �Է��ϼ���(�ѱ� �ȵ�) : ";
	cin.getline(str, 80, '\n');
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
		cout << "������ �߻��߽��ϴ�.";
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
		cout << "������ �߻��߽��ϴ�.";
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