#include <iostream>
#include <string>
using namespace std;

class Score {
	string name;
	int kor;
	int eng;
	int math;
public:
	void setName() {
		cout << "�̸� �Է�>> ";
		cin >> this->name;
	}
	void getName() {
		cout << name;
	}
	void setKor(int kor) {
		this->kor = kor;
	}
	void setEng(int eng) {
		this->eng = eng;
	}
	void setMath(int math) {
		this->math = math;
	}
	double calculateAve() {
		return (math + eng + kor) / 3.0;
	}
};
int main() {
	Score tls;
	int tmp;
	tls.setName();
	cout << "���� �Է�>> ";
	cin >> tmp;
	tls.setKor(tmp);
	cout << "���� �Է�>> ";
	cin >> tmp;
	tls.setEng(tmp);
	cout << "���� �Է�>> ";
	cin >> tmp;
	tls.setMath(tmp);
	cout << "��� : " << tls.calculateAve();
}