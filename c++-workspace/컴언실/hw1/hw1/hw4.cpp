#include <iostream>
using namespace std;
int main() {
	int num;
	cout << "Insert Number>>";
	cin >> num;
	switch (num % 3)
	{
	case 0:
		cout << "3의 배수입니다." << endl;
		break;
	case 1:
	case 2:
		cout << "3의 배수가 아닙니다." << endl;
	}
 }