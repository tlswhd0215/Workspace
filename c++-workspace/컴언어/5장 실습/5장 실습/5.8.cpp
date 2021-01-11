#include <iostream>
using namespace std;

class MyIntStack {
	int *p;
	int size;
	int tos;
public:
	MyIntStack() {
		tos = 0;
		size = 10;
		p = new int [size];
	}
	MyIntStack(int size) {
		tos = 0;
		this->size = size;
		p = new int[this->size];
	}
	MyIntStack(const MyIntStack& s);
	~MyIntStack() {
		delete[] p;
	}
	bool push(int n);
	bool pop(int &n);
};
MyIntStack::MyIntStack(const MyIntStack& s) {
	this->tos = s.tos;
	this->size = s.size;
	p = new int[size];
	for (int i = 0; i < tos; i++)
	{
		p[i] = s.p[i];
	}
}
bool MyIntStack::push(int n) {
	if (tos == 10)
		return false;
	p[tos] = n;
	tos++;
	return true;
}
bool MyIntStack::pop(int &n) {
	if (tos == 0)
		return false;
	tos--;
	n = p[tos];
	return true;
}

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;
}