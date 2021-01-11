#include "mystack.h"
#include <iostream>
using namespace std;

int main() {
	Stack<int> st;
	int menu;
	int tempData;
	int tempIndex;
	while (1) {
		cout << endl << "############################### �޴� ���� ###############################" << endl;
		cout << "1�� : push || 2�� : pop || 3�� : top " << endl;
		cout << "4�� : size || 5�� : empty || 6�� : print || 0�� : ����" << endl;
		cout << "�޴��� �����Ͻÿ� <-";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "�� �Է� <- ";
			cin >> tempData;
			st.push(tempData);
			break;
		case 2:
			if (!st.empty())
				st.pop();
			else
				cout << "������ ����ֽ��ϴ�!" << endl;
			break;
		case 3:
			if (!st.empty())
				cout<<st.top()<<endl;
			else
				cout << "������ ����ֽ��ϴ�!" << endl;
			break;
		case 4:
			cout << "������ ũ��� "<<st.size() << endl;
			break;
		case 5:
			if (!st.empty())
				cout << "������ ������� �ʽ��ϴ�!" << endl;
			else
				cout << "������ ����ֽ��ϴ�!" << endl;
			break;
		case 6:
			if (!st.empty())
				st.print();
			else
				cout << "������ ����ֽ��ϴ�!" << endl;
			break;
		case 0:
			return 0;
		default:
			break;
		}
	}
}