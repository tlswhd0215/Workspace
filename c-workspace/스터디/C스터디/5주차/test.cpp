#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<char> str1, str2;
	stack<char> temp1, temp2;
	stack<char> old1, old2;
	int n;
	string str, temp;
	char ch;
	cin >> str >> n;
	for (int i = 0; i < str.size(); i++) {
		str1.push(str[i]);
	}
	for (int i = 0; i < n; i++) {
		string order;
		if (i>0) {
			temp1 = str1;
			temp2 = str2;
		}
		if (order != "R") {
			temp = order;
			cin >> order;
		}
		else
			order = temp;
		if (!str1.empty()&&order=="ML") {
			ch = str1.top();
			str2.push(ch);
			str1.pop();
		}
		else if (!str2.empty() && order == "MR") {
			ch = str2.top();
			str1.push(ch);
			str2.pop();
		}
		else if (!str1.empty() && order == "DL") {
			str1.pop();
		}
		else if (!str2.empty() && order == "DR") {
			str2.pop();
		}
		else if (order == "R") {
			
		}
		else if (order == "Z") {
			str1 = temp1;
			str2 = temp2;
			temp1 = old1;
			temp2 = old2;
		}
		else if (order == "I") {
			cin >> ch;
			str1.push(ch);
		}
	}
	str1.push('*');
	while (!str1.empty()) {
		str2.push(str1.top());
		str1.pop();
	}
	while (!str2.empty()) {
		cout << str2.top();
		str2.pop();
	}
}