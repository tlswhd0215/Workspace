#include <iostream>
using namespace std;

class Stack {
	int tos;
	int p[10];
public:
	Stack() { tos = 0; }
	Stack& operator << (int x) {
		if (tos == 10)
			return *this;
		p[tos] = x;
		tos++;
		return *this;
	}
	bool operator !() { if (tos == 0)return true; else return false; }
	void operator >>(int& x) { tos--; x = p[tos];  }
};
int main() {
	Stack stack;
	stack << 3 << 5 << 10;
	while (true) {
		if (!stack)break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;
}