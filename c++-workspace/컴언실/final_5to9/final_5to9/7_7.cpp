#include <iostream>
using namespace std;

class Matrix {
	int n[4];
public:
	Matrix(int x1 = 0, int x2 = 0, int x3 = 0, int x4 = 0) { n[0] = x1; n[1] = x2; n[2] = x3; n[3] = x4; }
	void show() {
		cout << "Matrix = { " << n[0] << ' ' << n[1] << ' ' << n[2] << ' ' << n[3] << " }\n";
	}
	friend void operator >>(Matrix a, int x[]) {
		for (int i = 0; i < 4; i++)
		{
			x[i] = a.n[i];
		}
	}
	friend void operator <<(Matrix& a,int x[]) {
		for (int i = 0; i < 4; i++)
		{
			a.n[i] = x[i];
		}
	}
};
int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;

	for (int i = 0; i < 4; i++)cout << x[i] << ' ';
	cout << endl;
	b.show();
}