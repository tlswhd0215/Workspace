#include <iostream>
using namespace std;
#include "Add.h"
#include "Div.h"
#include "Mul.h"
#include "Sub.h"
int main(){
	int num1, num2;
	char op;
	Add a;
	Sub s;
	Mul m;
	Div d;
	while (1) {
		cout << "두 정수와 연산자를 입력하세요>>";
		cin >> num1 >> num2;
		if (num1 == 0 && num2 == 0)
			return 0;
		cin >> op;
		switch (op)
		{
		case '+':
			a.setValue(num1, num2);
			cout<<a.caculate()<<endl;
			break;
		case '-':
			s.setValue(num1,num2);
			cout << s.caculate() << endl;
			break;
		case '*':
			m.setValue(num1, num2);
			cout << m.caculate() << endl;
			break;
		case '/':
			d.setValue(num1, num2);
			cout << d.caculate() << endl;
			break;
		}
	}
}