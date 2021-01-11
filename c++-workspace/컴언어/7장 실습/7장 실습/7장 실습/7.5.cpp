#include <iostream>
using namespace std;

class Matrix {
	int x[4];
public:
	Matrix(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0) {
		x[0] = n1;
		x[1] = n2;
		x[2] = n3;
		x[3] = n4;
	}
	void show() { cout << "Matrix = [ " << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << " ]" << endl; }
	void operator >>(int* p);
	void operator <<(int* p);
};
void Matrix::operator >>(int* p) {
	for (int i = 0; i < 4; i++)
	{
		p[i] = x[i];
	}
}
void  Matrix::operator <<(int* p) {
	for (int i = 0; i < 4; i++)
	{
		x[i] = p[i];
	}
}
int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };  // 2���� ����� 4 ���� ���� ��
	a >> x; // a�� �� ���Ҹ� �迭 x�� ����. x[]�� {4,3,2,1}
	b << y; // �迭 y�� ���� ���� b�� �� ���ҿ� ����

	for (int i = 0; i < 4; i++)
		cout << x[i] << ' '; // x[] ���
	cout << endl;
	b.show();
}
