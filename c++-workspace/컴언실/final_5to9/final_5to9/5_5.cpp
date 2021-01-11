#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int r = 1) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	double getArea() { return radius * radius*3.14; }
	void display() { cout << "반지름이 " << radius  << "인 원입니다." << endl; }
};
void increaseBy(Circle& a, Circle b)
{
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}
int main() {
	Circle x(10), y(5);
	increaseBy(x, y);
	x.display();
}