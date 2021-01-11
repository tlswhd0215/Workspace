#include <iostream>
using namespace std;

int main() {
	int a = 3;
	int &r = a;

	cout << "a: " << a << endl;
	cout << "r: " << r << endl;

	cout << "&a: " << &a << endl;
	cout << "&r: " << &r << endl;
	r = 5;
	cout << "a: " << a << endl;
	cout << "r: " << r << endl;
}
