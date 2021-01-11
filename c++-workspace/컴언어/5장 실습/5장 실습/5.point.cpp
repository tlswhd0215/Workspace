#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point() { x = y = 0; }
	Point(int a, int b) { this->x= a;this->y= b; }
	void SetXY(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
	void display() { cout << "(" << x << "," << y << ")" << endl; }
};
Point addPoint(Point a, Point b);
void increaseBy(Point &a, int i);
bool isEqual(Point a, Point b);
int main() {
	Point p1(2, 5), p2(-3, 3), p3;

	p3 = addPoint(p1, p2);
	cout << "p1 = ";
	p1.display();
	cout << "p2 = ";
	p2.display();
	cout << "p3 = ";
	p3.display();
	cout << "----------------------------" << endl;
	
	increaseBy(p1, 5);
	cout << "p1 = ";
	p1.display();
	cout << "----------------------------" << endl;

	if (isEqual(p1, p3))
		cout << "p1 == p3" << endl;
	else
		cout << "p1 != p2" << endl;

	return 0;
}
Point addPoint(Point a, Point b) {
	Point tmp(a.getX() + b.getX(), a.getY() + b.getY());
	return tmp;
}
void increaseBy(Point &a, int i) {
	a.SetXY(a.getX() + i, a.getY() + i);
}
bool isEqual(Point a, Point b) {
	if (a.getX() == b.getY()&&a.getY() == b.getY())
		return true;
	else return false;  
}