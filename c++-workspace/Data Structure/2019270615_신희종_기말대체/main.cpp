#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
class postfix {
	stack<string> operand;
	string post;
public:
	string exp;
	void setEXP() { cin >> exp; }
	string getEXP() { return exp; }
	int Setpostfix();
	void Getpostfix() {
		post = "";
		exp = "";
		if (Setpostfix()) {
			cout << "�����ڰ� �߸��ƽ��ϴ�." << endl;
		}
		else {
			cout << post << endl;
		}
	}
};
int main() {
	postfix cal;
	cout << "postfix ��ȯ�� �Դϴ�." << endl;
	cout << "�����ڿ� �� �׸��� ��ȣ ���̿��� ������ �־� �Է��Ͻʽÿ�." << endl;
	cout << "���Ḧ ���� ��� quit�� �Է����ֽʽÿ�." << endl;
	while (1) {
		cout << ">>";
		cal.setEXP();
		if (cal.getEXP() == "quit") {
			cal.exp = "";
			break;
		}
		cal.Getpostfix();
	}
}
int postfix::Setpostfix() {
	int len = exp.length();
	int start_pos = 0;
	int cur_pos = 0;
	string temp;
	while (len > cur_pos) {
		if (exp[cur_pos] == ' ') {
			cur_pos++;
			continue;
		}
		if (exp[start_pos] >= 48 && exp[start_pos] <= 57) {
			post.append(exp.substr(start_pos, cur_pos - start_pos));
			post += ' ';
			start_pos = cur_pos;
			cur_pos++;
			continue;
		}
		else {
			if (exp[cur_pos] == '(') {
				operand.push("(");
			}
			else if (exp[cur_pos] == ')') {
				while (operand.top() != "(") {
					post.append(operand.top());
					operand.pop();
					post += ' ';
				}
				operand.pop();
			}
			else if (exp[cur_pos] == '*' || exp[cur_pos] == '/') {
				if (operand.empty()||operand.top()=="("|| operand.top()=="+"|| operand.top()=="-") {
					temp = exp[cur_pos];
					operand.push(temp);
				}
				else {
					while (!operand.empty() && operand.top() != "("&& operand.top() != "+" && operand.top() != "-") {
						post.append(operand.top());
						operand.pop();
						post += ' ';
					}
					temp = exp[cur_pos];
					operand.push(temp);
				}
			}
			else if (exp[cur_pos] == '-' || exp[cur_pos] == '+') {
				if (operand.empty() || operand.top() == "(") {
					temp = exp[cur_pos];
					operand.push(temp);
				}
				else {
					while (!operand.empty() && operand.top() != "(") {
						post.append(operand.top());
						operand.pop();
						post += ' ';
					}
					temp = exp[cur_pos];
					operand.push(temp);
				}
			}
			else {
				return 1;
			}

			start_pos = cur_pos;
			cur_pos++;
			continue;
		}
	}
	while (!operand.empty()) {
		post.append(operand.top());
		operand.pop();
		post += ' ';
	}
	return 0;
}