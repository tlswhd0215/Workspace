#include <iostream>
using namespace std;

class CoffeeMachine {
public:
	int cof;
	int water;
	int sugar;
	CoffeeMachine();
	CoffeeMachine(int c, int w, int s);
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugarCoffee();
	void show();
	void fill();
};
CoffeeMachine::CoffeeMachine() :CoffeeMachine(10, 10, 10) {}
CoffeeMachine::CoffeeMachine(int c, int w, int s) {
	cof = c;
	water = w;
	sugar = s;
}
void CoffeeMachine::drinkEspresso() {
	if (cof < 1 || water < 1)
	{
		cout << "��ᰡ �����Ͽ� ���������Ҹ� ���� �� �����ϴ�." << endl;
		CoffeeMachine::show();
	}
	else
	{
		cof--;
		water--;
	}
}
void CoffeeMachine::drinkAmericano() {
	if (cof < 1 || water < 2)
	{
		cout << "��ᰡ �����Ͽ� �Ƹ޸�ī�븦 ���� �� �����ϴ�." << endl;
		CoffeeMachine::show();
	}
	else
	{
		cof--;
		water -= 2;
	}
}
void CoffeeMachine::drinkSugarCoffee() {
	if (cof < 1 || water < 2 || sugar < 1)
	{
		cout << "��ᰡ �����Ͽ� ����Ŀ�Ǹ� ���� �� �����ϴ�." << endl;
		CoffeeMachine::show();
	}
	else
	{
		cof--;
		water -= 2;
		sugar--;
	}
}
void CoffeeMachine::show() {
	cout << "Ŀ�� �ӽ� ����, Ŀ��:" << cof << " ��:" << water << " ����:" << sugar << endl;
}
void CoffeeMachine::fill() {
	cof = 10;
	sugar = 10;
	water = 10;
}
int main() {
	CoffeeMachine java(5, 8, 2);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();
}