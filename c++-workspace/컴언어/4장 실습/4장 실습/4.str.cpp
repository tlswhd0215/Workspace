#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1 = "shj";
	string str2 = "2019270615";
	string cmp;
	string tmp;
	string namenum;
	cout << "�̸� �Է�>> ";
	cin >> cmp;
	if (str1.compare(cmp) == 0)
		cout << "�̸� Ȯ��" << endl;
	else
	{
		cout << "�̸��� Ʋ���ϴ�." << endl;
		return 0;
	}
	cout << "�� : " << str1.substr(0, 1) << " �̸� : " << str1.substr(1) << endl;
	cout << "�й� �Է�>> ";
	cin >> tmp;
	if (str2.compare(tmp) == 0)
		cout << "�й� Ȯ��" << endl;
	else
	{
		cout << "�й��� Ʋ���ϴ�." << endl;
		return 0;
	}
	if (tmp.find("2706") < tmp.size())
	{
		cout << "���� �Դϴ�." << endl;
	}
	namenum = str1;
	namenum += str2;
	if (stoi(tmp) / 1000000 % 100 == 19)
		str1.insert(0, "19�й�");
	str1.replace(0, 4, "����19");
	cout << str1;
}