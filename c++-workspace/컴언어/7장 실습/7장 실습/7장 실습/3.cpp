#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle(int radius = 0) {
		this->radius = radius;
	}
	Circle operator ++(int i);
	friend void operator ++(Circle& op);
	void show() {
		cout << "radius = " << radius << " �� ��" << endl;
	}
};
Circle Circle:: operator ++(int i) {
	Circle tmp = *this;
	this->radius++;
	return tmp;
}
void operator ++(Circle& op) {
	op.radius++;
}
int main() {
	Circle a(5), b(4);
	++a; // �������� 1 ���� ��Ų��.
	b = a++; // �������� 1 ���� ��Ų��.
	a.show();
	b.show();

	return 0;
}
