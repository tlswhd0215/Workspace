#include <iostream>
using namespace std;

class MyVector {
	int *mem;
	int size;
public:
	MyVector(int n=100, int val=0);
	~MyVector() { delete[] mem; }
	void display() {
		for (int i = 0; i < size; i++)
			cout << mem[i] << endl;
	}
};
MyVector::MyVector(int n, int val) {
	mem = new int[n];
	size = n;
	for (int i = 0; i < n; i++)mem[i] = val;
}
int main() {
	MyVector a, b(10, 10);
	cout << "a 출력" << endl;
	a.display();
	cout << "b출력" << endl;
	b.display();

}