#include <iostream>
#include <string>
using namespace std;


class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius= radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};
class NamedCircle :public Circle {
	string name;
public:
	NamedCircle(int radius=0, string name="") :Circle(radius) { this->name = name; }
	void show() { cout << "�������� " << getRadius() << "�� " << name<<endl; }
	void setName(string name) { this->name = name; }
	string getName() { return name; }
};
int main() {
	NamedCircle waffle(3, "waffle");
	waffle.show();

	NamedCircle pizza[5];
	string temp1;
	int temp2;

	cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���." << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ">> ";
		cin >> temp2 >> temp1;
		pizza[i].setName(temp1);
		pizza[i].setRadius(temp2);
	}
	int max, index;
	max = pizza[0].getArea();
	index = 0;
	for(int i=1;i<5;i++)
	{
		if (max < pizza[i].getArea())
		{
			max = pizza[i].getArea();
			index = i;
		}
	}
	cout << "���� ������ ū ���ڴ� " << pizza[index].getName() << "�Դϴ�." << endl;
}