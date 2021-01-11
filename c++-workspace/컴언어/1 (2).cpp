#include <iostream>
#include <string>
using namespace std;

class Convert {
protected:
	double before, after;
public:
	Convert(double b) {
		before = b;
	}
	virtual void compute()=0;
	virtual void display()=0;
	virtual ~Convert() {};
};
class LtoG :public Convert
{
public:
	LtoG(double b) :Convert(b) {};
	virtual void compute() {
		after = before / 3.7854;
	}
	virtual void display() {
		cout << before << " ���� = " << after << " ����"<<endl;
	}
};
class CtoF :public Convert
{
public:
	CtoF(double b) :Convert(b) {};
	virtual void compute() {
		after = before * 9 / 5 + 32;
	}
	virtual void display() {
		cout << before << " ���� = " << after << " ȭ��"<<endl;
	}
};
class MtoKM :public Convert
{
public:
	MtoKM(double b) :Convert(b) {};
	virtual void compute() {
		after = before *1.609344;
	}
	virtual void display() {
		cout << before<<" ���� = "<<after << " ų�ι���"<<endl;
	}
};
int main() {
	Convert *p[3] = { new MtoKM(23.2),new LtoG(10.3),new CtoF(24.5) };

	for (int i = 0; i < 3; i++)
	{
		p[i]->compute();
		p[i]->display();
	}
	for (int i = 0; i < 3; i++)
	{
		delete p[i];
	}
	return 0;
}
