#include <iostream>
#include <string>
using namespace std;

class student {
	string name;
protected:
	int computer, korean;
public:
	student(string n, int c, int k)
	{
		name = n;
		computer = c;
		korean = k;
	};
	string getName() { return name; }
	virtual double getAverage() = 0;
	virtual ~student() {}
};
class firstGrade:public student {
	int math;
public:
	firstGrade(string n, int c, int k, int m) :student(n, c, k) { math = m; }
	virtual double getAverage() { return (computer + korean + math) / 3.0; }
};
class secondGrade :public student {
	int science,moral;
public:
	secondGrade(string n, int c, int k, int s, int m) :student(n, c, k) { science = s; moral = m; }
	virtual double getAverage() { return (computer + korean + moral+science) / 5.0; }
};
class thirdGrade :public student {
	int english, history;
public:
	thirdGrade(string n, int c, int k, int e, int h) :student(n, c, k) { english = e; history = h; }
	virtual double getAverage() { return (computer + korean + english + history) / 5.0; }
};
int main() {
	student *s[4];
	s[0] = new firstGrade("��浿", 80, 70, 70);
	s[1] = new secondGrade("�Ѹ�", 70, 60, 90, 70);
	s[2] = new thirdGrade("��ġ", 90, 100, 90, 100);
	s[3] = new secondGrade("�����", 80, 90, 60, 100);

	for (int i = 0; i < 4; i++)
	{
		cout << "�̸� : " << s[i]->getName() << " ��� : " << s[i]->getAverage() << endl;
	}
	for (int i = 0; i < 4; i++)
	{
		delete s[i];
	}
}