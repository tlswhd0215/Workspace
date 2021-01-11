#include <iostream>
#include <string>
using namespace std;

class Trace {
	static int cid;
	static string tag[100];
	static string inform[100];
public:
	static void put(string t, string i) 
	{
		tag[cid] = t;
		inform[cid] = i;
		cid++;
	}
	static void print(string t="")
	{
		if (t == "")
		{
			cout << "----- ��� Trace ������ ����մϴ�. -----" << endl;
			for (int i = 0; i < cid; i++)
				cout << tag[i] << ":" << inform[i] << endl;
			return;
		}
		cout << "----- f()�±��� Trace ������ ����մϴ�. -----" << endl;
		for (int i = 0; i < cid; i++)
		{
			if (tag[i] == "f()")
				cout <<tag[i]<<":"<< inform[i]<<endl;
		}
	}
};
int Trace::cid = 0;
string Trace::tag[100] = { " " };
string Trace::inform[100] = { " " };
void f() {
	int a, b, c;
	cout << "�� ���� ������ �Է��ϼ���>>";
	cin >> a >> b;
	Trace::put("f()", "������ �Է� �޾���");
	c = a + b;
	Trace::put("f()", "�� ���");
	cout << "���� " << c << endl;
}
int main() {
	Trace::put("main()", "���α׷� �����մϴ�");
	f();
	Trace::put("main()", "����");
	Trace::print("f()");
	Trace::print();

}