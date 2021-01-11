#include <iostream>
using namespace std;
class Circle{
	int radius;
public:
	Circle(int r = 0) { radius = r; }
	void display() { cout << "반지름이 " << radius  << "인 원 "  << endl; }
	friend Circle operator ++(Circle& a) {
		a.radius++;
		return a;
	}
	friend Circle operator ++(Circle& a, int i) {
		Circle tmp = a;
		a.radius++;
		return tmp;
	}
};
int main() {
	Circle a(5), b(4);
	++a;
	b = a++;
	a.display();
	b.display();
}