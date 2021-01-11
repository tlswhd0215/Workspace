#include <iostream>
#define SIZE 3
using namespace std;

class Circle {
	int radius;
public:
	Circle() {
		radius = 1;
	}
	Circle(int radius)
	{
		this->radius = radius;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return radius * radius*3.14;
	}
};
int main() {
	Circle cir[SIZE];
	int tmpradius, cnt = 0;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "�� " << i << "�� ������ >> ";
		cin >> tmpradius;
		cir[i].setRadius(tmpradius);
		if (cir[i].getArea() > 100)
			cnt++;
	}
	cout << "������ 100���� ū ���� " << cnt << "�� �Դϴ�.";
}