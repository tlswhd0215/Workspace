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
		cout << "재료가 부족하여 에스프레소를 만들 수 없습니다." << endl;
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
		cout << "재료가 부족하여 아메리카노를 만들 수 없습니다." << endl;
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
		cout << "재료가 부족하여 설탕커피를 만들 수 없습니다." << endl;
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
	cout << "커피 머신 상태, 커피:" << cof << " 물:" << water << " 설탕:" << sugar << endl;
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