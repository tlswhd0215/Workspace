#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int r = 1) { radius = r; }
	friend Circle operator ++(Circle &a) {
		a.radius++;
		return a;
	}
	void show() { cout << "radius=" << radius << endl; }
};
int main() {
	Circle c1, c2(20);
	c1 = ++c2;
	c1.show();
	c2.show();
	++c1;
	c1.show();
	c2.show();
	++c2;
	c1.show();
	c2.show();
}