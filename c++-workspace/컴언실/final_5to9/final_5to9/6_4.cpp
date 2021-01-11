#include <iostream>
using namespace std;

class MyVector {
	int *mem;
	int size;
public:
	MyVector(int n = 100, int value = 100) {
		mem = new int[n];
		size = n;
		for (int i = 0; i < size; i++)mem[i] = value;
	}
	~MyVector() { delete[] mem; }
	void show() { 
		for (int i = 0; i < size; i++)cout << mem[i] << ' ';
		cout << endl;
	}
};
int main() {
	MyVector a, b(10, 20);
	a.show();
	b.show();
}
