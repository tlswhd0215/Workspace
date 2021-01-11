#include <iostream>
#include <ctime>
using namespace std;
/*
#1
class Random {
public:
	Random(); // ������. ���� seed�� �����Ѵ�.
	int next(); // ���� ������ ����.
	int nextInRange(int low, int high); // low�� high ������ ���� ������ ����.
};
Random::Random() {
	srand((unsigned)time(0));
}
int Random::next() {
	return rand();
}
int Random::nextInRange(int low, int high) {
	return rand() % high + low;
}
int main() {
	Random r;
	// RAND_MAX �� <cstlib> ����� ����Ǿ� �ִ� ��ũ�� ���, 32767�� ���� ������ �ִ�
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "4 ������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2���� 4 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
}
*/

/*
#2
class Circle {
	int radius;
public:
	Circle(int r) { radius = r; };
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "�������� " << radius << "�� ��" << endl; }
};
void increaseBy(Circle &a, Circle b) {
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}
int main() {
	Circle x(10), y(5);
	increaseBy(x, y); // x�� �������� 15�� ���� ������� �Ѵ�.
	x.show(); // �������� 15�� �� ��ü x ���� ���!
}*/
class MyIntStack {
	int p[10];
	int tos; // ������ ����⸦ ����Ű�� �ε���
public:
	MyIntStack() { tos = 0; };
	bool push(int n); // ���� n Ǫ��. �� �� ������ false, �ƴϸ� true ����
	bool pop(int &n); // ���Ͽ� n�� ����.������ ��� ������ false, �ƴϸ� true ����
};
bool MyIntStack::push(int n) {
	if (tos == 10)
		return false;
		p[tos] = n;
		tos++;
		return true;
}
bool MyIntStack::pop(int &n) {
	if (tos == 0)
		return false;
	tos--;
	n = p[tos];
	return true;
}
int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) { // 11���� Ǫ���Ѵ�.
		if (a.push(i))
			cout << i << ' '; // Ǫ�õ� �� ����
		else
			cout << endl << i + 1 << " ��° stack full" << endl;
	}

	int n;
	for (int i = 0; i < 11; i++) { // 11���� ���Ѵ�.
		if (a.pop(n))
			cout << n << ' '; // �� �� �� ���
		else
			cout << endl << i + 1 << " ��° stack empty";
	}

	cout << endl;
	return 0;
}