#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "반지름이 "<<radius << "인 원" << endl; }
};
void swap(Circle *a, Circle *b);
void swap(Circle &a, Circle &b);
bool bigger(Circle a, Circle b, Circle &c);
void increaseBy(Circle &a, Circle b);
int main() {
	Circle x(10), y(3), c(7), z;
	swap(x, y);
	cout << "=== 참조 버전의 swap() 호출 후===" << endl;
	cout << "\tx 객체:";
	x.show();
	cout << "\ty 객체: ";
	y.show();

	swap(&x, &y);
	cout << "=== 포인터 버전의 swap() 호출 후===" << endl;
	cout << "\tx 객체:";
	x.show();
	cout << "\ty 객체: ";
	y.show();

	cout << endl << "===bigger(x,y,z) 호출===" << endl;
	if (bigger(x, y, z))
		cout << "\tx와 y 중 더 큰 객체의 반지름은" << z.getRadius() << endl;
	else
		cout << "\t객체 x와 y의 크기는 같다" << endl;

	increaseBy(c, y);
	cout << endl << "===increaseBy함수 호출 후===" << endl;
	cout << "\tc객체: ";
	c.show();

	cout << endl << "===bigger(x,c,z) 호출===" << endl;
	if (bigger(x, c, z))
		cout << "\tx와 c 중 더 큰 객체의 반지름은" << z.getRadius() << endl;
	else
		cout << "\t객체 x와 c의 크기는 같다" << endl;
	return 0;
}
void swap(Circle *a, Circle *b) {
	Circle tmp;
	tmp.setRadius(a->getRadius());
	a->setRadius(b->getRadius());
	b->setRadius(tmp.getRadius());
}
void swap(Circle &a, Circle &b) {
	Circle tmp;
	tmp.setRadius(a.getRadius());
	a.setRadius(b.getRadius());
	b.setRadius(tmp.getRadius());
}
bool bigger(Circle a, Circle b, Circle &big) {
	if (a.getRadius() > b.getRadius())
	{
		big.setRadius(a.getRadius());
		return true;
	}
	else if (a.getRadius() < b.getRadius())
	{
		big.setRadius(a.getRadius());
		return true;
	}
	else
		return false;
}
void increaseBy(Circle &a, Circle b) {
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}
