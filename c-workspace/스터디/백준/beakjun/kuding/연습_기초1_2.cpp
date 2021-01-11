#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int A, B, V;
	cin >> A >> B >> V;
	cout << (int)ceil((V - A) / (double)(A - B)) + 1;
}