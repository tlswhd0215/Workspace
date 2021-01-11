#include <iostream>
using namespace std;

class Matrix {
	int n[4];
public:
	Matrix(int x1 = 0, int x2 = 0, int x3 = 0, int x4 = 0) { n[0] = x1; n[1] = x2; n[2] = x3; n[3] = x4; }
	void show() {
		cout << "Matrix = { " << n[0] << ' ' << n[1] << ' ' << n[2] << ' ' << n[3] << " }\n";
	}
	friend Matrix operator + (Matrix a, Matrix b)
	{ 
		Matrix tmp; 
		tmp = a;
		for (int i = 0; i < 4; i++)
			tmp.n[i] += b.n[i];
		return tmp;
	}
	friend Matrix operator +=(Matrix& a, Matrix b)
	{
		for (int i = 0; i < 4; i++)
			a.n[i] += b.n[i];
		return a;
	}
	friend bool operator == (Matrix a,Matrix b)
	{
		for (int i = 0; i < 4; i++)
		{
			if (b.n[i] != a.n[i])
				return false;
		}
		return true;
	}
};
int main() {
	Matrix a{ 1,2,3,4 }, b{ 2,3,4,5 }, c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;
}