#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	void setRadius(int radius);
	double getArea();
};
void Circle::setRadius(int radius) {
	Circle::radius = radius;
}
double Circle::getArea() {
	return radius * radius*3.14;
}
int main() {
	int n;
	int radius, cnt = 0;
	cout << "���� ���� >> ";
	cin >> n;
	if (n < 1)
		return 0;
	Circle *p = new Circle[n];
	if (!p)
		exit(1);
	for (int i = 0; i < n; i++)
	{
		cout << "�� " << i + 1 << "�� ������ >> ";
		cin >> radius;
		p[i].setRadius(radius);
		if (p[i].getArea() > 100)
			cnt++;
	}
	cout << "������ 100���� ū ���� " << cnt << "�� �Դϴ�";
	delete[] p;
}