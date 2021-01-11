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
	cout << "생성" << endl;
}
Grade::Grade(string name, int kor, int eng) {
	cout << "정보 입력된 객체 생성" << endl;
}

Grade::~Grade() {
	cout << "소멸" << endl;
}
void Grade::showGrade() {
	cout << "국어 점수: " << kor << " 영어 점수: " << eng << " 총합: " << sum << " 평균: " << ave << endl;
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