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
		cout << "�̸�: " << getName() << endl;
		cout << "����: " << kor << endl;
		cout << "��ǻ��: " << com << endl;
		cout << "����: " << math << endl;
		cout << "---------------------------" << endl << "���: " << getAverage() << endl << endl;
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
		cout << "�̸�: " << getName() << endl;
		cout << "����: " << kor << endl;
		cout << "��ǻ��: " << com << endl;
		cout << "����: " << science << endl;
		cout << "����: " << moral << endl;
		cout << "---------------------------" << endl << "���: " << getAverage() << endl << endl;
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
		cout << "�̸�: " << getName() << endl;
		cout << "����: " << kor << endl;
		cout << "��ǻ��: " << com << endl;
		cout << "����: " << eng << endl;
		cout << "����: " << his << endl;
		cout << "---------------------------" << endl << "���: " << getAverage() << endl << endl;
	}

};
int main() {
	FirstGrade f("ȫ�浿",90,81,88);
	SecondGrade s("�念��", 73, 91, 99, 68);
	ThirdGrade t("������", 81, 53, 80, 96);

	f.display();
	s.display();
	t.display();
}