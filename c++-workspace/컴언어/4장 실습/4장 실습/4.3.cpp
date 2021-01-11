#include<iostream>
#include<string>
using namespace std;

int main() {
	string text;
	int cnt = 0,tmp=0;
	cout << "문자열 입력>> ";
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
	
	

	cout << "문자 a는 " << cnt << "개 있습니다.";

}