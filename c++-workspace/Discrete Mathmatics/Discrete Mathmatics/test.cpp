#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	double a;
	string b = "2.9999999999999999999999999999999999999";
	cin >> a;
	cout.precision(20);
	cout << stod(b) << endl;
	cout << stoi(b) << endl;
	if (stod(b) == stoi(b))
		cout << "same" << endl;
	cout << ceil(a) << endl << floor(a)<<endl;
	cout << ceil(stod(b)) << endl << floor(stod(b)) << endl;
}