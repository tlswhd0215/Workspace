#include<iostream>
using namespace std;
#include "Mul.h"
void Mul::setValue(int x, int y) {
	a = x;
	b = y;
}
int Mul::caculate() {
	return a * b;
}
