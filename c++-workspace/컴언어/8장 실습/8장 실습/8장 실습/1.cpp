#include <iostream>
#include <string>
using namespace std;
class Point {//포인트 클래스 생성
	int x, y;
public:
	Point(int x, int y) {	this->x = x; this->y = y;	}
	int getX() { return x; }
	int gety() {return y;}
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};
class ColorPoint : public Point//포인트 클래스를 상속받는 컬러 포인트 클래스 생성
{
	string color;
public:
	ColorPoint(int x=0, int y=0, string color = "BLACK") :Point(x, y) {//생성자에서 부모클래스 생성자에 변수 전달
		this->color = color;
	}
	void show() { cout << color << "색으로 (" << this->getX() << ", " << this->gety() << ")에 위치한 점입니다." << endl; }
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
	ColorPoint cp1(5, 5, "RED");//컬러 포인트 변수에서 포인트 클래스의 멤버함수에 접근이 가능
	cp1.show();
	cp1.setPoint(10, 20);
	cp1.setColor("BLUE");
	cp1.show();

	ColorPoint cp2(5, 5);
	cp2.show();
	cp2.setPoint(3, 7);
	cp2.setColor("GREEN");
	cp2.show();
	ColorPoint zeroPoint; // BLANK에 (0, 0) 11
	zeroPoint.show(); // zeroPoint 를 출력한다.

	return 0;
}