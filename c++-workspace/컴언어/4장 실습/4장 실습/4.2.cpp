#include <iostream>
using namespace std;

int main() {
	int *p = new int[5];
	if (!p)
		return 0;
	int sum = 0;
	cout << "정수 5개 입력>> ";
	for (int i = 0; i < 5; i++)
	{
		cin >> p[i];
		sum += p[i];
	}
	double ave = sum / 5.0;
	cout << "평균 " << ave;
	delete[]p;
}