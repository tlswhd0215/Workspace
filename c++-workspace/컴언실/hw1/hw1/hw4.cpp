#include <iostream>
using namespace std;
int main() {
	int num;
	cout << "Insert Number>>";
	cin >> num;
	switch (num % 3)
	{
	case 0:
		cout << "3�� ����Դϴ�." << endl;
		break;
	case 1:
	case 2:
		cout << "3�� ����� �ƴմϴ�." << endl;
	}
 }