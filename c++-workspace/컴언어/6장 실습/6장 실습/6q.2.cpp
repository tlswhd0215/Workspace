#include<iostream>
using namespace std;
void split_real(double real,int *num,double *frac) {
	*num = (int)real;
	*frac = real - *num;
}
void split_real(double real,int &num,double &frac) {
	num = (int)real;
	frac = real - num;
}
int main() {
	int integer;
	double real, fraction;
	cout << "�Ǽ� �Է�: ";
	cin >> real;
	split_real(real, &integer, &fraction);

	cout << real << "�� �����δ� " << integer << ", �Ǽ��δ� " << fraction << "�Դϴ�" << endl;

	cout << "�Ǽ� �Է�: ";
	cin >> real;
	split_real(real, integer, fraction);
	cout << real << "�� �����δ� " << integer << ", �Ǽ��δ� " << fraction << "�Դϴ�" << endl;
}
