#include<iostream>
using namespace std;
#include "Div.h"
void Div::setValue(int x, int y) {
	a = x;
	b = y;
}
int Div::caculate() {
	if (b == 0)
	{
		cout << "0���� ���� �� �����ϴ�." << endl;
		return 0;
	}
	return a / b;
}