#include <iostream>
#include <string>
using namespace std;
class Point {//����Ʈ Ŭ���� ����
	int x, y;
public:
	Point(int x, int y) {	this->x = x; this->y = y;	}
	int getX() { return x; }
	int gety() {return y;}
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};
class ColorPoint : public Point//����Ʈ Ŭ������ ��ӹ޴� �÷� ����Ʈ Ŭ���� ����
{
	string color;
public:
	ColorPoint(int x=0, int y=0, string color = "BLACK") :Point(x, y) {//�����ڿ��� �θ�Ŭ���� �����ڿ� ���� ����
		this->color = color;
	}
	void show() { cout << color << "������ (" << this->getX() << ", " << this->gety() << ")�� ��ġ�� ���Դϴ�." << endl; }
	void setPoint(int x, int y);
	void setColor(string color);
};
void ColorPoint::setColor(string color) {
	this->color = color;
}
void ColorPoint::setPoint(int x, int y) {
	move(x, y);
}
int main() {
	ColorPoint cp1(5, 5, "RED");//�÷� ����Ʈ �������� ����Ʈ Ŭ������ ����Լ��� ������ ����
	cp1.show();
	cp1.setPoint(10, 20);
	cp1.setColor("BLUE");
	cp1.show();

	ColorPoint cp2(5, 5);
	cp2.show();
	cp2.setPoint(3, 7);
	cp2.setColor("GREEN");
	cp2.show();
	ColorPoint zeroPoint; // BLANK�� (0, 0) 11
	zeroPoint.show(); // zeroPoint �� ����Ѵ�.

	return 0;
}