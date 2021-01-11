#include <iostream>
#include <cmath>
using namespace std;

class ThreeD {
	int x, y, z;
public:
	ThreeD(int i = 0, int j = 0, int k = 0) { x = i; y = j; z = k; }
	double distance() { return sqrt(double(x*x + y * y + z * z)); }
	friend ostream& operator << (ostream &out, ThreeD ob);
	friend bool operator !(ThreeD a);
	ThreeD operator -(ThreeD op);
	bool operator !=(ThreeD op);
	ThreeD& operator -();
	ThreeD& operator --();
	ThreeD operator --(int x);
	bool operator >=(ThreeD op);
};
ostream& operator << (ostream &out, ThreeD ob) {
	out << "(" << ob.x << ", " << ob.y << ", " << ob.z << ")";
	return out;
}
bool operator !(ThreeD a) {
	if (a.x == 0 && a.y == 0 && a.z == 0)
		return true;
	else
		return false;
}
ThreeD ThreeD:: operator -(ThreeD op) {
	ThreeD tmp;
	tmp.x = x - op.x;
	tmp.y = y - op.y;
	tmp.z = z - op.z;
	return tmp;
}
bool ThreeD:: operator !=(ThreeD op) {
	if (x == op.x&&y == op.y&&z == op.z)
		return false;
	else return true;
}
ThreeD& ThreeD::operator -() {
	x = -x;
	y = -y;
	z = -z;
	return *this;
}
ThreeD& ThreeD:: operator --() {
	x--;
	y--;
	z--;
	return *this;
}
ThreeD ThreeD:: operator --(int n) {
	ThreeD tmp = *this;
	x--;
	y--;
	z--;
	return tmp;
}
bool ThreeD::operator >=(ThreeD op) {
	if (this->distance() >= op.distance())
		return true;
	else
		return false;
}

int main() {
	ThreeD a(1, 2, 3), b(10, 20, 30), c(-1, -2, -1), d;

	if (!d)cout << "객체 d는 원점입니다\n\n";

	cout << "Value of after d = b - a - c\n";
	d = b - a - c;
	cout << b << " - " << a << " - " << c << " = " << d << endl;

	if (b != d)
		cout << endl << b << " != " << d << endl;

	d = -c;
	cout << endl << "Value of after d= -c" << endl;
	cout << "-" << c << " = " << d << endl;

	c = --b;
	cout << endl << "Value of a after c = --b" << endl;
	cout << "c = " << c << ", b= " << b << endl;

	c = b--;
	cout << endl << "Value of a after c = b--" << endl;
	cout << "c = " << c << ", b" << b << endl << endl;

	if (c >= b)
		cout << "|" << c << "| >= |" << b << "|" << endl;
	else
		cout << "|" << c << "| < |" << b << "|" << endl;
	return 0;
}