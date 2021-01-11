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
		cout << "radius = " << radius << " 인 원" << endl;
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
	++a; // 반지름을 1 증가 시킨다.
	b = a++; // 반지름을 1 증가 시킨다.
	a.show();
	b.show();

	return 0;
}
