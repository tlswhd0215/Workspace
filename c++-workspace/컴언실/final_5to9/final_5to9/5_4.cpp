#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big)
{
	if (a > b)
		big = a;
	else if (a < b)
		big = b;
	else
		return false;
	return true;
}
int main() {
	int a, b;
	int big;
	cout << "정수 두 개 입력>>";
	cin >> a >> b;
	bigger(a, b, big);
	cout << big;
}