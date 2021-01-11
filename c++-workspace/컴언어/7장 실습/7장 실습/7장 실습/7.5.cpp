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
	int x[4], y[4] = { 1,2,3,4 };  // 2차원 행렬의 4 개의 원소 값
	a >> x; // a의 각 원소를 배열 x에 복사. x[]는 {4,3,2,1}
	b << y; // 배열 y의 원소 값을 b의 각 원소에 설정

	for (int i = 0; i < 4; i++)
		cout << x[i] << ' '; // x[] 출력
	cout << endl;
	b.show();
}
