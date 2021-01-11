#include <iostream>
using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s[], int s2[], int size) {
		int* p = new int[size*2];
		for (int i = 0; i<size; i++)
		{
			p[i] = s[i];
		}
		for (int i = size; i < size*2; i++) {
			p[i] = s2[i - size];
		}
		return p;
	}
	static int* remove(int s[], int s2[], int size, int& retSize) {
		int* p = new int[size];
		int cnt = 0;
		for (int i = 0; i < size; i++) {
			bool sd = true;
			for (int j = 0; j < size; j++) {
				if (s[i] == s2[j])
				{
					sd = false;
				}
			}
			if (sd)
			{
				p[cnt] = s[i];
				cnt++;
			}
		}
		retSize = cnt;
		if (retSize == 0)
		{
			return NULL;
		}
		return p;
	}
};
int main() {
	int x[5];
	int y[5];
	int* p1, *p2;
	int size;
	cout << "������ 5 �� �Է��϶�. �迭 x�� �����Ѵ�>>";
	for (int i = 0; i < 5; i++)
	{
		cin >> x[i];
	}
	cout << "������ 5 �� �Է��϶�. �迭 y�� �����Ѵ�>>";
	for (int i = 0; i < 5; i++)
	{
		cin >> y[i];
	}
	cout << "��ģ ���� �迭�� ����Ѵ�" << endl;
	p1=ArrayUtility2::concat(x, y, 5);
	for (int i = 0; i < 10; i++)
	{
		cout<<p1[i]<<' ';
	}
	cout << endl;
	p2 = ArrayUtility2::remove(x, y, 5, size);
	cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ " << size << endl;
	for (int i = 0; i < size; i++)
	{
		cout << p2[i] << ' ';
	}
}