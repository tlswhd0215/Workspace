#include <iostream>
#include <string>
#include <time.h>
using namespace std;
//1��
/*int big(int x, int y, int z = 100);
int main() {
	int x = big(3, 5); // 3�� 5�� ū �� 5�� �ִ밪 100���� �����Ƿ�, 5 ����
	int y = big(300, 60); // 300�� 60�� ū �� 300�� �ִ밪 100���� ũ�Ƿ�, 100 ����
	int z = big(30, 60, 50); // 30�� 60 �� ū �� 60�� �ִ밪 50���� ũ�Ƿ�, 50 ����
	cout << x << ' ' << y << ' ' << z << endl;
	return 0;
}
int big(int x, int y, int z) {
	return (x > y ? x : y) > z ? z : (x > y ? x : y);
}*/
//2��
/*
class Person {
	static int numPerson;
	int id;
	double weight;
	string name;
public:
	Person(int id = 1, string name = "Grace", double weight = 20.5) {
		this->id = id;
		this->name = name;
		this->weight=weight;
		numPerson++;
	};
	static void nPerson() {
		cout << Person::numPerson << endl;
	};
	void show() { cout << id << ' ' << weight << ' ' << name << ' ' << numPerson << endl; }
	~Person() {
		numPerson--;
	}
};
int Person::numPerson = 0;

int main() {
	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
}
// ������ main ��
int main() {
	Person grace;
	grace.show();

	Person helen(13, "Helen", 32.5);
	helen.show();

	Person *p = new Person[2]{ {43, "Tera"}, {98, "Hera"} };
	p[0].show();
	p[1].show();
	Person::nPerson();

	delete[] p;
	Person::nPerson();
}
*/
//3��
/*class Random {
public:
	// �׻� �ٸ� �������� �߻���Ű��	// ���� seed�� �����ϴ� �Լ�
	static void seed() {
		srand((unsigned)time(0));
	}

	//min�� max ������ ���� ���� ����
	static int nextInt(int min = 0, int max = 32767);
	static char nextAlphabet();
	// 0���� ũ�ų� ���� 1���� ���� �Ǽ� ����
	//static double nextDouble();
};
int Random::nextInt(int min, int max) {
	return rand() % max + min;
}
char Random::nextAlphabet() {
	char arrAlphabet[] = { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	return arrAlphabet[rand() % 52 + 0];
}
int main() {
	Random::seed();
	cout << "1���� 100���� ������ ���� 10���� ����մϴ�" << endl;
	for (int i = 0; i < 10; i++)
		cout << Random::nextInt(1, 100) << ' ';
	cout << endl;

	cout << "���ĺ��� �����ϰ� 10���� ����մϴ�" << endl;
	for (int i = 0; i < 10; i++)
		cout << Random::nextAlphabet() << ' ';
	cout << endl;

	cout << "������ �Ǽ��� 10���� ����մϴ�" << endl;
	for (int i = 0; i < 5; i++)
		cout << Random::nextDouble() << ' ';
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout << Random::nextDouble() << ' ';
	cout << endl;
}
*/
//4��
/*
class Circle {
	static int count;
	int radius;
public:
	Circle(int r=0) {
		radius = r;
		count++;
	}
	~Circle() {
		count--;
	}
	void show() {
		cout << "Radius: " << radius << ", Count: " << count << endl;
	}
}; 
int Circle::count = 0;
int main() {
	Circle a(5);
	a.show();

	Circle *p = new Circle[2];

	for (int i = 0; i < 2; i++)
		p[i].show();

	a.show();

	delete[] p;
	a.show();
}
*/