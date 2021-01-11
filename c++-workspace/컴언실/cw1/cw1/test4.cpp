#include <iostream>
using namespace std;
int Add(int x) { return x + x; }
int Add(int x, int y) { return x + y; }
double Add(double x, double y) { return x + y; }
int main() {
	cout << Add(3) << endl;
	cout << Add(2, 3) << endl;
	cout << Add(2.3, 3.2) << endl;
}
