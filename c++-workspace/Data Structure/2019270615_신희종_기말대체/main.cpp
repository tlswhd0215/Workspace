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
			cout << "연산자가 잘못됐습니다." << endl;
		}
		else {
			cout << post << endl;
		}
	}
};
int main() {
	postfix cal;
	cout << "postfix 변환기 입니다." << endl;
	cout << "연산자와 값 그리고 괄호 사이에는 공백을 넣어 입력하십시오." << endl;
	cout << "종료를 원할 경우 quit을 입력해주십시오." << endl;
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