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
	cout << "실수 입력: ";
	cin >> real;
	split_real(real, &integer, &fraction);

	cout << real << "의 정수부는 " << integer << ", 실수부는 " << fraction << "입니다" << endl;

	cout << "실수 입력: ";
	cin >> real;
	split_real(real, integer, fraction);
	cout << real << "의 정수부는 " << integer << ", 실수부는 " << fraction << "입니다" << endl;
}
