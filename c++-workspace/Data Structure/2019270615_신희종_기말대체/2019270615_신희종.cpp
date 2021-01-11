#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <string>
using namespace std;

class Postfix {
	string stack;
	string postfix;
	string infix;
public:
	void getInfix() { cin >> infix; }
	void push(char op);
	char pop();
	void makePostfix();
	string getPostfix() { return postfix; }
};
bool bIsOperator(char op) {
	if (op == '^' || op == '*' || op == '/' || op == '+' || op == '-')
		return 1;
	else
		return 0;
}
int priority(char op) {
	if (op == '^')
		return 2;
	else if (op == '*' || op == '/')
		return 1;
	else if (op == '+' || op == '-')
		return 0;
	else
		return -1;
}
void Postfix::push(char op) {
	stack += op;
}
char Postfix::pop() {
	char temp = stack.back();
	stack[stack.length() - 1] = '\0';
	return temp;
}
void Postfix::makePostfix() {
	int i=0;
	char var=infix[i];
	char temp;

	push('(');
	infix += ')';

	while (var != '\0') {
		if (var == '(')
			push(var);
		else if (isdigit(var) || isalpha(var)) {
			postfix += var;
		}
		else if (bIsOperator(var) == 1) {
			temp = pop();
			while (bIsOperator(var) && priority(temp) >= priority(var)) {
				postfix += temp;
				temp = pop();
			}
			push(temp);
			push(var);
		}
		else if (var == ')') {
			temp = pop();
			while (temp != '(') {
				postfix += temp;
				temp = pop();
			}
		}
		else {
			cout << "�߸��� �Է��Դϴ�" << endl;
			exit(1);
		}
		i++;
		var = infix[i];
	}
	postfix += "\0";
}
int main() {
	Postfix post;
	cout << "�� ���ڷ� �̷���� ���ڳ� ���ڷ� �� ���� �Է� >> ";
	post.getInfix();
	post.makePostfix();
	cout << post.getPostfix();
}
