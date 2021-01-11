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
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		cin >> name >> radius;
		p[i].setCircle(name, radius);
	}
}
CircleManager::~CircleManager() {
	delete[] p;
}
void CircleManager::searchByName() {
	char name[80];
	cout << "검색하고자 하는 원의 이름 >> ";
	cin >> name;
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(p[i].getName(), name)) {
			cout << name << "의 면적은 " << p[i].getArea() << endl;
			return;
		}

	}
	cout << name << "는 찾을 수 없습니다." << endl;
}
void CircleManager::searchByArea() {
	int area, cnt = 0;
	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> area;
	cout << area << "보다 큰 원을 검색합니다." << endl;
	for (int i = 0; i < size; i++)
	{
		if (p[i].getArea() > area)
		{
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
			cnt++;
		}
	}
	if (cnt == 0)
		cout << "면적이 " << area << "보다 큰 원은 없습니다.";
}
int main() {
	int size;
	cout << "원의 개수 >> ";
	cin >> size;
	CircleManager cm(size);
	cm.searchByName();
	cm.searchByArea();
}