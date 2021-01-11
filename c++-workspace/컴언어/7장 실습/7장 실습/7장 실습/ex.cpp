#include <iostream>
using namespace std;
class Fraction {//�м� Ŭ���� ����
	int num;//�и�� ���� ��� ����
	int denom;
public:
	Fraction(int n = 1, int d = 1) { num = n; denom = d; }
	friend ostream& operator<<(ostream& out, Fraction op2);//�м� ��� ������ ������
	Fraction operator+(Fraction op);//�м������� ���� ������ ������
	Fraction operator++(int x);//���� ������ ++ ������
	friend Fraction operator--(Fraction op);//���� ������ -- ������
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

	cout << "(" << f1 << ")++ = ";
	f4 = f1++;
	cout << f1 << "\n";
	cout << "���� ���� ���� ��,f4 = " << f4 << "\n\n";

	cout << "--(" << f2 << ") = ";
	f4 = --f2;
	cout << f2 << "\n";
	cout << "���� ���� ���� ��, f4 = " << f4 << "\n\n";
}