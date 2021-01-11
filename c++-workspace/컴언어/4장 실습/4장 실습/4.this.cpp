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
		cout << "이름 입력>> ";
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
	cout << "국어 입력>> ";
	cin >> tmp;
	tls.setKor(tmp);
	cout << "영어 입력>> ";
	cin >> tmp;
	tls.setEng(tmp);
	cout << "수학 입력>> ";
	cin >> tmp;
	tls.setMath(tmp);
	cout << "평균 : " << tls.calculateAve();
}