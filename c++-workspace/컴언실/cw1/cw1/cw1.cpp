#include<iostream>
#include <string>
using namespace std;
class Grade {
public:
	string name;
	int sum, kor, eng;
	double ave;
	void showGrade();
	void getSA();
	Grade();
	Grade(string name, int kor, int eng);
	~Grade();
};
Grade::Grade() {
	cout << "����" << endl;
}
Grade::Grade(string name, int kor, int eng) {
	cout << "���� �Էµ� ��ü ����" << endl;
}

Grade::~Grade() {
	cout << "�Ҹ�" << endl;
}
void Grade::showGrade() {
	cout << "���� ����: " << kor << " ���� ����: " << eng << " ����: " << sum << " ���: " << ave << endl;
}
void Grade::getSA() {
	sum = kor + eng;
	ave = sum / 2.0;
}
int main() {
	Grade kim;
	kim.kor = 95;
	kim.eng = 72;
	kim.getSA();
	kim.showGrade();
}