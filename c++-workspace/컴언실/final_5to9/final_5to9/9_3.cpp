#include <iostream>
#include <string>
using namespace std;

class LoopAdder {
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = "") { this->name = name; }
	int getX() { return x;}
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};
void LoopAdder::read() {
	cout << name << ":" << endl;
	cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
	cin >> x >> y;
}
void LoopAdder::write() {
	cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�." << endl;
}
void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}
class ForLoopAdder :public LoopAdder {
public:
	ForLoopAdder(string n) :LoopAdder(n) {};
	virtual int calculate() {
		int suma = 0;
		for (int i = getX(); i <= getY(); i++)
		{
			suma += i;
		}
		return suma;
	}
};
class WhileLoopAdder :public LoopAdder {
public:
	WhileLoopAdder(string n) :LoopAdder(n) {};
	virtual int calculate() {
		int suma = 0;
		int i = getX();
		while (i <= getY()) {
			suma += i;
			i++;
		}
		return suma;
	}
};
class DoWhileLoopAdder :public LoopAdder {
public:
	DoWhileLoopAdder(string n) :LoopAdder(n) {};
	virtual int calculate() {
		int suma = 0;
		int i = getX();
		do
		{
			suma += i;
			i++;
		} while (i <= getY());
		return suma;
	}
};
int main() {
	ForLoopAdder forLoop("For Loop");
	forLoop.run();

	WhileLoopAdder whileLoop("While Loop");
	whileLoop.run();

	DoWhileLoopAdder doWhileLoop("Do while Loop");
	doWhileLoop.run();
}
