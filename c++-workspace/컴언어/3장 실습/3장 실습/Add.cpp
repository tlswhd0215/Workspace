#include<iostream>
using namespace std;
#include "Add.h"
void Add::setValue(int x, int y) {
	a = x;
	b = y;
}
int Add::caculate() {
	return a + b;
}