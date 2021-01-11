#include <iostream>
#include <ctime>
using namespace std;
/*
#1
class Random {
public:
	Random(); // 생성자. 랜덤 seed를 설정한다.
	int next(); // 랜던 정수를 리턴.
	int nextInRange(int low, int high); // low와 high 사이의 랜덤 정수를 리턴.
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
	// RAND_MAX 는 <cstlib> 헤더에 선언되어 있는 매크로 상수, 32767의 값을 가지고 있다
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수
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
	void show() { cout << "반지름이 " << radius << "인 원" << endl; }
};
void increaseBy(Circle &a, Circle b) {
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}
int main() {
	Circle x(10), y(5);
	increaseBy(x, y); // x의 반지름이 15인 원을 만들고자 한다.
	x.show(); // 반지름이 15가 된 객체 x 정보 출력!
}*/
class MyIntStack {
	int p[10];
	int tos; // 스택의 꼭대기를 가리키는 인덱스
public:
	MyIntStack() { tos = 0; };
	bool push(int n); // 정수 n 푸시. 꽉 차 있으면 false, 아니면 true 리턴
	bool pop(int &n); // 팝하여 n에 저장.스택이 비어 있으면 false, 아니면 true 리턴
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
	for (int i = 0; i < 11; i++) { // 11개를 푸시한다.
		if (a.push(i))
			cout << i << ' '; // 푸시된 값 에코
		else
			cout << endl << i + 1 << " 번째 stack full" << endl;
	}

	int n;
	for (int i = 0; i < 11; i++) { // 11개를 팝한다.
		if (a.pop(n))
			cout << n << ' '; // 팝 한 값 출력
		else
			cout << endl << i + 1 << " 번째 stack empty";
	}

	cout << endl;
	return 0;
}