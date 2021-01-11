#include "mystack.h"
#include <iostream>
using namespace std;

int main() {
	Stack<int> st;
	int menu;
	int tempData;
	int tempIndex;
	while (1) {
		cout << endl << "############################### 메뉴 선택 ###############################" << endl;
		cout << "1번 : push || 2번 : pop || 3번 : top " << endl;
		cout << "4번 : size || 5번 : empty || 6번 : print || 0번 : 종료" << endl;
		cout << "메뉴를 선택하시오 <-";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "값 입력 <- ";
			cin >> tempData;
			st.push(tempData);
			break;
		case 2:
			if (!st.empty())
				st.pop();
			else
				cout << "스택이 비어있습니다!" << endl;
			break;
		case 3:
			if (!st.empty())
				cout<<st.top()<<endl;
			else
				cout << "스택이 비어있습니다!" << endl;
			break;
		case 4:
			cout << "스택의 크기는 "<<st.size() << endl;
			break;
		case 5:
			if (!st.empty())
				cout << "스택이 비어있지 않습니다!" << endl;
			else
				cout << "스택이 비어있습니다!" << endl;
			break;
		case 6:
			if (!st.empty())
				st.print();
			else
				cout << "스택이 비어있습니다!" << endl;
			break;
		case 0:
			return 0;
		default:
			break;
		}
	}
}