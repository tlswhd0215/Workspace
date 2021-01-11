#include<iostream>
#include<cstring>
using namespace std;

class Circle {
	int radius;
	char name[80];
public:
	void setCircle(char* name, int radius);
	double getArea();
	char* getName();
};
void Circle::setCircle(char* name, int radius)
{
	strcpy(this->name, name);
	this->radius = radius;
}
double Circle::getArea() {
	return 3.14*radius*radius;
}
char* Circle::getName() {
	return name;
}
class CircleManager {
	Circle *p;
	int size;
public:
	CircleManager(int size);
	~CircleManager();
	void searchByName();
	void searchByArea();
};
CircleManager::CircleManager(int size) {
	int radius;
	char name[80];
	this->size = size;
	p = new Circle[size];
	if (!p)
		exit(1);
	for (int i = 0; i < size; i++)
	{
		cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
		cin >> name >> radius;
		p[i].setCircle(name, radius);
	}
}
CircleManager::~CircleManager() {
	delete[] p;
}
void CircleManager::searchByName() {
	char name[80];
	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
	cin >> name;
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(p[i].getName(), name)) {
			cout << name << "�� ������ " << p[i].getArea() << endl;
			return;
		}

	}
	cout << name << "�� ã�� �� �����ϴ�." << endl;
}
void CircleManager::searchByArea() {
	int area, cnt = 0;
	cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
	cin >> area;
	cout << area << "���� ū ���� �˻��մϴ�." << endl;
	for (int i = 0; i < size; i++)
	{
		if (p[i].getArea() > area)
		{
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << endl;
			cnt++;
		}
	}
	if (cnt == 0)
		cout << "������ " << area << "���� ū ���� �����ϴ�.";
}
int main() {
	int size;
	cout << "���� ���� >> ";
	cin >> size;
	CircleManager cm(size);
	cm.searchByName();
	cm.searchByArea();
}