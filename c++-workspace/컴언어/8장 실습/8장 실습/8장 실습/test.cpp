#include <iostream>
#include <string>
using namespace std;
//1��
/*
class Circle {
	int radius;
public:
	Circle(int radius = 0) {
		this->radius = radius;
	}
	int getRadius() {
		return radius;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return 3.14*radius*radius;
	}
};
class NamedCircle :public Circle {
	string name;
public:
	NamedCircle(int r, string n) :Circle(r) {
		this->name = n;
	}
	void show() {
		cout << "�������� " << getRadius() << "�� " << name << endl;
	}
};
int main() {
	NamedCircle waffle(3, "waffle"); // �������� 3�̰� �̸��� waffle�� ��
	waffle.show();

	return 0;
}*/
//2��

class Point {
	int x, y;
public:
	Point(int x, int y) {
		this->x = x; this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) {
		this->x = x;
		this->y = y;
	}
}; 
class ColorPoint:public Point {
	string name;
public:
	ColorPoint(int x, int y, string n) :Point(x, y) {
		name = n;
	}
	void show() {
		cout << name << "������ (" << getX() << ", " << getY() << ") �� ��ġ�� ���Դϴ�." << endl;
	}
	void setPoint(int op1, int op2) {
		move(op1, op2);
	}
	void setColor(string c) {
		name = c;
	}
};
int main() {
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();

	return 0;
}
