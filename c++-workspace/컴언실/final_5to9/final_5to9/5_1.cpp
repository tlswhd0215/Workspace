#include <iostream> 
#include <string>
using namespace std;

class Circle {
	int radius;
	string name;
public:
	Circle(int r = 1, string n = "noname") { radius = r; name = n; }
	double getArea() { return radius * radius*3.14; }
	void display() { cout << "�������� " << radius << "�̰� ���̰� " << getArea() << "�� �� "<<name<<"�Դϴ�." << endl; }
};
void swap(Circle& a, Circle& b)
{
	Circle tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int main() {
	Circle a(10,"pizza"), b(100,"chip");
	a.display();
	b.display();

	swap(a, b);
	a.display();
	b.display();

	return 0;
}