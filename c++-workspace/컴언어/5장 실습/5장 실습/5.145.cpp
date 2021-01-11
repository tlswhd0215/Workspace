#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "�������� "<<radius << "�� ��" << endl; }
};
void swap(Circle *a, Circle *b);
void swap(Circle &a, Circle &b);
bool bigger(Circle a, Circle b, Circle &c);
void increaseBy(Circle &a, Circle b);
int main() {
	Circle x(10), y(3), c(7), z;
	swap(x, y);
	cout << "=== ���� ������ swap() ȣ�� ��===" << endl;
	cout << "\tx ��ü:";
	x.show();
	cout << "\ty ��ü: ";
	y.show();

	swap(&x, &y);
	cout << "=== ������ ������ swap() ȣ�� ��===" << endl;
	cout << "\tx ��ü:";
	x.show();
	cout << "\ty ��ü: ";
	y.show();

	cout << endl << "===bigger(x,y,z) ȣ��===" << endl;
	if (bigger(x, y, z))
		cout << "\tx�� y �� �� ū ��ü�� ��������" << z.getRadius() << endl;
	else
		cout << "\t��ü x�� y�� ũ��� ����" << endl;

	increaseBy(c, y);
	cout << endl << "===increaseBy�Լ� ȣ�� ��===" << endl;
	cout << "\tc��ü: ";
	c.show();

	cout << endl << "===bigger(x,c,z) ȣ��===" << endl;
	if (bigger(x, c, z))
		cout << "\tx�� c �� �� ū ��ü�� ��������" << z.getRadius() << endl;
	else
		cout << "\t��ü x�� c�� ũ��� ����" << endl;
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
