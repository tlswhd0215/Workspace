#include <iostream>
using namespace std;
int add_sum_MtoN(int a, int b = 1);

int main() {
	cout << "100 ~ 201������ Ȧ���� ��: " << add_sum_MtoN(100, 201) << endl;
	cout << "11 ~ 30������ Ȧ���� ��: " << add_sum_MtoN(30, 11) << endl;
	cout << "1 ~ 50������ Ȧ���� ��: " << add_sum_MtoN(50) << endl;
	cout << "5 ~ 5������ Ȧ���� ��: " << add_sum_MtoN(5, 5) << endl;
	cout << "6 ~ 6������ Ȧ���� ��: " << add_sum_MtoN(6, 6) << endl;
	return 0;
}
int add_sum_MtoN(int a, int b) {
	int fir, sec, sum = 0;
	if (b >= a)
	{
		fir = a;
		sec = b;
	}
	else
	{
		fir = b;
		sec = a;
	}
	if (fir % 2 == 0)
	{
		fir++;
	}
	for (int i = fir; i <= sec; i+=2)
	{
		sum += i;
	}
	return sum;

}