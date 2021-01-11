#include <iostream>
#include <string>
using namespace std;
class Student {
	string name;
protected:
	int kor, com;
public:
	Student(string name = "noname", int kor = 0, int com = 0) {
		this->name = name;
		this->kor = kor;
		this->com = com;
	}
	string getName() {
		return name;
	}
};
class FirstGrade :public Student {
	int math;
public:
	FirstGrade(string name, int kor, int com, int math) :Student(name, kor, com) {
		this->math = math;
	}
	double getAverage() {
		return (kor + com + math) / 3.0;
	}
	void display() {
		cout << "이름: " << getName() << endl;
		cout << "국어: " << kor << endl;
		cout << "컴퓨터: " << com << endl;
		cout << "수학: " << math << endl;
		cout << "---------------------------" << endl << "평균: " << getAverage() << endl << endl;
	}

};
class SecondGrade :public Student {
	int science;
	int moral;
public:
	SecondGrade(string name, int kor, int com, int science,int moral) :Student(name, kor, com) {
		this->science = science;
		this->moral = moral;
	}
	double getAverage() {
		return (kor + com + science+moral )/ 4.0;
	}
	void display() {
		cout << "이름: " << getName() << endl;
		cout << "국어: " << kor << endl;
		cout << "컴퓨터: " << com << endl;
		cout << "과학: " << science << endl;
		cout << "도덕: " << moral << endl;
		cout << "---------------------------" << endl << "평균: " << getAverage() << endl << endl;
	}

};
class ThirdGrade :public Student {
	int eng;
	int his;
public:
	ThirdGrade(string name, int kor, int com, int eng,int his) :Student(name, kor, com) {
		this->eng = eng;
		this->his = his;
	}
	double getAverage() {
		return (kor + com + eng+his)/4.0;
	}
	void display() {
		cout << "이름: " << getName() << endl;
		cout << "국어: " << kor << endl;
		cout << "컴퓨터: " << com << endl;
		cout << "영어: " << eng << endl;
		cout << "역사: " << his << endl;
		cout << "---------------------------" << endl << "평균: " << getAverage() << endl << endl;
	}

};
int main() {
	FirstGrade f("홍길동",90,81,88);
	SecondGrade s("장영실", 73, 91, 99, 68);
	ThirdGrade t("정도전", 81, 53, 80, 96);

	f.display();
	s.display();
	t.display();
}