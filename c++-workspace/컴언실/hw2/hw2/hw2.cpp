#include <iostream>
using namespace std;
int main() {
	int a;
	int& ref = a;
	a = 10;
	cout << "a = " << a << endl;
	cout << "ref = "<<ref << endl;
	++ref;
	cout << "a = "<<a << endl;
	cout << "ref = " << ref << endl;
}