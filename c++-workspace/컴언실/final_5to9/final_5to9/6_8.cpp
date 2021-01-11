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
			cout << "----- 모든 Trace 정볼르 출력합니다. -----" << endl;
			for (int i = 0; i < cid; i++)
				cout << tag[i] << ":" << inform[i] << endl;
			return;
		}
		cout << "----- f()태그의 Trace 정보를 출력합니다. -----" << endl;
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
	cout << "두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << endl;
}
int main() {
	Trace::put("main()", "프로그램 시작합니다");
	f();
	Trace::put("main()", "종료");
	Trace::print("f()");
	Trace::print();

}