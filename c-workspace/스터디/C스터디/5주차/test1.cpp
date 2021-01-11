#include <iostream>
#include <string>
#include <stack>
using namespace std;
class object {
public:
	string str;
	string order;
	int index;
};
int main() {
	object obj[10000];
	cin >> obj[0].str;
	obj[0].str += "*";   
	obj[0].index = obj[0].str.length() - 1;	 // starÀÇ À§Ä¡
	int count;
	cin >> count;
	obj[count];
	for (int i = 0; i < count; i++) {
		cin >> obj[i].order;
	start:;
		if (i > 0) {
			obj[i].index = obj[i - 1].index;
			obj[i].str = obj[i - 1].str;
		}
		if (obj[i].order == "ML" && obj[i].index > 0) {
			obj[i].str.insert(obj[i].index - 1, "*");
			obj[i].str.erase(obj[i].index + 1, 1);
			obj[i].index--;
		}
		else if (obj[i].order == "MR" && obj[i].index < obj[i].str.length() - 1) {
			obj[i].str.erase(obj[i].index, 1);
			obj[i].str.insert(obj[i].index + 1, "*");
			obj[i].index++;
		}
		else if (obj[i].order == "DL" && obj[i].index > 0) {
			obj[i].str.erase(obj[i].index - 1, 1);
			obj[i].index--;
		}
		else if (obj[i].order == "DR" && obj[i].index < obj[i].str.length() - 1) {
			obj[i].str.erase(obj[i].index + 1, 1);
		}
		else if (obj[i].order == "R") {
			if (obj[i - 1].order == "Z") {
				i--;
				count--;
				goto start;
			}
			else {
				obj[i].order = obj[i - 1].order;
				goto start;
			}
		}
		else if (obj[i].order == "Z") {
			obj[i].order = "";
			i--;
			obj[i].order = "Z";
			obj[i].str = obj[i - 1].str;
			obj[i].index = obj[i - 1].index;
			count--;
		}
		else if (obj[i].order == "I") {
			string subInput;
			cin >> subInput;
			obj[i].str.insert(obj[i].index, subInput);
			obj[i].index++;
		}
	}
	cout << obj[count - 1].str;
}