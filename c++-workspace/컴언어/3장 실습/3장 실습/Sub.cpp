#include<iostream>
using namespace std;
#include "Sub.h"
void Sub::setValue(int x, int y) {
	a = x;
	b = y;
}
int Sub::caculate() {
	return a - b;
}