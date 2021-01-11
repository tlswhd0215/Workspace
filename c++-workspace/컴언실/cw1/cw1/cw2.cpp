#include <iostream>
#include <string>
#include <time.h>
using namespace std;
//1번
/*int big(int x, int y, int z = 100);
int main() {
	int x = big(3, 5); // 3과 5중 큰 값 5는 최대값 100보다 작으므로, 5 리턴
	int y = big(300, 60); // 300과 60중 큰 값 300이 최대값 100보다 크므로, 100 리턴
	int z = big(30, 60, 50); // 30과 60 중 큰 값 60이 최대값 50보다 크므로, 50 리턴
	cout << x << ' ' << y << ' ' << z << endl;
	return 0;
}
int big(int x, int y, int z) {
	return (x > y ? x : y) > z ? z : (x > y ? x : y);
}*/
//2번
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
// 수정된 main 문
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
//3번
/*class Random {
public:
	// 항상 다른 랜덤수를 발생시키기	// 위한 seed를 설정하는 함수
	static void seed() {
		srand((unsigned)time(0));
	}

	//min과 max 사이의 랜덤 정수 리턴
	static int nextInt(int min = 0, int max = 32767);
	static char nextAlphabet();
	// 0보다 크거나 같고 1보다 적은 실수 리턴
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
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++)
		cout << Random::nextInt(1, 100) << ' ';
	cout << endl;

	cout << "알파벳을 랜덤하게 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++)
		cout << Random::nextAlphabet() << ' ';
	cout << endl;

	cout << "랜덤한 실수를 10개를 출력합니다" << endl;
	for (int i = 0; i < 5; i++)
		cout << Random::nextDouble() << ' ';
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout << Random::nextDouble() << ' ';
	cout << endl;
}
*/
//4번
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