#include <iostream>
using namespace std;

int main() {
	int *p = new int[5];
	if (!p)
		return 0;
	int sum = 0;
	cout << "���� 5�� �Է�>> ";
	for (int i = 0; i < 5; i++)
	{
		cin >> p[i];
		sum += p[i];
	}
	double ave = sum / 5.0;
	cout << "��� " << ave;
	delete[]p;
}