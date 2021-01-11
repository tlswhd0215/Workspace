#include <iostream>
using namespace std;
class Fraction {
	int num;
	int denom;
public:
	Fraction(int n = 1, int d = 1) { num = n; denom = d; }
	friend ostream& operator<<(ostream& out, Fraction op2);
	Fraction operator+(Fraction op);
	bool operator==(Fraction op);
	friend bool operator<(Fraction op, Fraction op2);
	Fraction& operator*=(Fraction op);
	Fraction operator^(int op);
	friend Fraction operator/ (int x, Fraction op2);
	friend Fraction operator~(Fraction op);
	Fraction operator++(int x);
	friend Fraction operator--(Fraction op);
};
ostream& operator<<(ostream& out, Fraction op2) {
	out << op2.num << "/" << op2.denom;
	return out;
}
Fraction Fraction::operator+(Fraction op) {
	Fraction temp;
	temp.num = num * op.denom + denom * op.num;
	temp.denom = denom * op.denom;
	return temp;
}
bool Fraction::operator==(Fraction op) {
	if ((double)num / denom == (double)op.num / op.denom)
		return true;
	return false;
}
bool operator<(Fraction op, Fraction op2) {
	if (((double)op.num / op.denom) < (double)op2.num / op2.denom)
		return true;
	return false;
}
Fraction& Fraction::operator*=(Fraction op) {
	num *= op.num;
	denom *= op.denom;
	return *this;
}
Fraction Fraction::operator^(int op) {
	Fraction tmp(num, denom);
	tmp.num = pow(tmp.num, op);
	tmp.denom = pow(tmp.denom, op);
	return tmp;
}
Fraction operator/ (int x, Fraction op2) {
	Fraction temp = op2;
	temp.num = x * temp.denom;
	temp.denom = op2.num;
	return temp;
}
Fraction operator~(Fraction op) {
	Fraction tmp = op;
	tmp.num = op.denom;
	tmp.denom = op.num;
	return tmp;
}
Fraction Fraction::operator++(int x) {
	Fraction tmp(num, denom);
	num += denom;
	return tmp;
}
Fraction operator--(Fraction op) {
	op.num -= op.denom;
	Fraction tmp = op;
	return tmp;
}
int main() {
	Fraction f1(3, 4), f2(2, 5), f3, f4(7, 15), f5(6, 15);
	f3 = f1 + f2;
	cout << f1 << " + " << f2 << " = " << f3 << "\n\n";

	if (f2 == f5) cout << f2 << " == " << f5 << "\n\n";
	if (f2 == f4) cout << f2 << " == " << f4 << "\n\n";

	if (f2 < f1) cout << f2 << " < " << f1 << "\n\n";

	f1 *= f2;
	cout << f1 << " *=" << f2 << "===> f1 = " << f1 << "\n\n";

	f3 = f2 ^ 3;
	cout << "( " << f2 << " )^3 = " << f3 << "\n\n";

	f3 = 5 / f2;
	cout << "5 / (" << f2 << ") = " << f3 << "\n\n";

	f3 = ~f2;
	cout << "~(" << f2 << ") = " << f3 << "\n\n";

	cout << "(" << f1 << ")++ = ";
	f4 = f1++;
	cout << f1 << "\n";
	cout << "후위 연산 수행 후,f4 = " << f4 << "\n\n";

	cout << "--(" << f2 << ") = ";
	f4 = --f2;
	cout << f2 << "\n";
	cout << "전위 연산 수행 후, f4 = " << f4 << "\n\n";
}


