#include<iostream>
#include<string>
using namespace std;

int main() {
	string text;
	int cnt = 0,tmp=0;
	cout << "���ڿ� �Է�>> ";
	getline(cin, text);
	//(1)
	/*for (int i = 0; i < text.length(); i++)
	{
		if (text.at(i) == 'a')
			cnt++;
	}*/
	//(2)
	for (int i = 0; i < text.length(); i++) {
		if (text.find('a', i) <text.length())
		{
			cnt++;
			i = text.find('a', i);
		}
	}
	
	

	cout << "���� a�� " << cnt << "�� �ֽ��ϴ�.";

}