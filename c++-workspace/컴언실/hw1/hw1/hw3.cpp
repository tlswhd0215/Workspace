#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cout << "두 수 입력" << endl;
	cin >>a >> b;
	if (a > b)
		cout << a << " > " << b << endl;
	else if (a == b)
		cout << a << " = " << b << endl;
	else
		cout << a << " < " << b << endl;
}