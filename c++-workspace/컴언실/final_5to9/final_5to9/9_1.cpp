#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�.";
		cout << getSourceString() << "�� �Է��ϼ���>> ";
		cin >> src;
		cout << "��ȯ ��� : " << convert(src) << getDestString() << endl;
	}
};
class WonToDollar :public Converter{
public:
	WonToDollar(double n) :Converter(n){  }
	virtual string getSourceString() { return "��"; }
	virtual string getDestString() { return "�޷�"; }
	virtual double convert(double src) { return (double)src / ratio; }
};
class KmToMile :public Converter{
public:
	KmToMile(double n) :Converter(n) {}
	virtual double convert(double src) { return src / ratio; }
	virtual string getSourceString() { return "Km"; }
	virtual string getDestString() { return "Mile"; }
};
int main() {
	WonToDollar wd(1010);
	wd.run();

	KmToMile toMile(1.609344);
	toMile.run();
}
