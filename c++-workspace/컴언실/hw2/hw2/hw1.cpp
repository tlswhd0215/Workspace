#include<iostream>
using namespace std;
void func(int *d) {
	cout << *d;
}
int main()
{
	int a;
	a = 10;
	func(&a);
}