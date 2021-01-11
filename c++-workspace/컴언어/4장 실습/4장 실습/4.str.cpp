#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1 = "shj";
	string str2 = "2019270615";
	string cmp;
	string tmp;
	string namenum;
	cout << "이름 입력>> ";
	cin >> cmp;
	if (str1.compare(cmp) == 0)
		cout << "이름 확인" << endl;
	else
	{
		cout << "이름이 틀립니다." << endl;
		return 0;
	}
	cout << "성 : " << str1.substr(0, 1) << " 이름 : " << str1.substr(1) << endl;
	cout << "학번 입력>> ";
	cin >> tmp;
	if (str2.compare(tmp) == 0)
		cout << "학번 확인" << endl;
	else
	{
		cout << "학번이 틀립니다." << endl;
		return 0;
	}
	if (tmp.find("2706") < tmp.size())
	{
		cout << "컴융 입니다." << endl;
	}
	namenum = str1;
	namenum += str2;
	if (stoi(tmp) / 1000000 % 100 == 19)
		str1.insert(0, "19학번");
	str1.replace(0, 4, "컴융19");
	cout << str1;
}