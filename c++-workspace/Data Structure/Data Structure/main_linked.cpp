#include "linked.h"
#include <iostream>
using namespace std;

int main() {
	LinkedList<int> list_linked;
	int menu;
	int tempData;
	int tempIndex;
	while (1) {
		cout << endl << "############################### �޴� ���� ###############################" << endl;
		cout << "1�� : ������ �ڵ� ���� || 2�� : �ε��� ���� ���� || 3�� : �ε��� ���� ���� " << endl;
		cout << "4�� : ������ �˻� ���� || 5�� : ������ �˻� || 6�� : ���� �ε��� Ž��" << endl;
		cout << "7�� : ������ ���� ���ϱ� || 8�� : ��ü ����ϱ� || 9�� : ����" << endl;
		cout << "�޴��� �����Ͻÿ� <-";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "�� �Է� <- ";
			cin >> tempData;
			list_linked.InsertAuto(tempData);
			break;
		case 2:
			cout << "�� �Է� <- ";
			cin >> tempData;
			cout << "�ε��� �Է� <- ";
			cin >> tempIndex;
			if (list_linked.Insert(tempData, tempIndex) == -1)
				cout << "����!" << endl;
			break;
		case 3:
			cout << "������ �ε��� �Է� <- ";
			cin >> tempIndex;
			if (list_linked.DeleteIndex(tempIndex) == -1)
				cout << "����!" << endl;
			break;
		case 4:
			cout << "�� �Է� <- ";
			cin >> tempData;
			if (list_linked.DeleteData(tempData) == -1)
				cout << "����!" << endl;
			break;
		case 5:
			cout << "�� �Է� <- ";
			cin >> tempData;
			tempIndex = list_linked.GetIndex(tempData);
			if (tempIndex == -1)
				cout << "����!" << endl;
			else
				cout << tempIndex << "�� �����մϴ�!" << endl;
			break;
		case 6:
			cout << "�ε��� �Է� <- ";
			cin >> tempIndex;
			tempData = list_linked.GetData(tempIndex);
			cout << tempIndex << "�� ���� " << tempData << "�Դϴ�!" << endl;
			break;
		case 7:
			cout << "�������� ������ " << list_linked.GetNumOfData() << "�� �Դϴ�!" << endl;
			break;
		case 8:
			for (int i = 0; i < list_linked.GetNumOfData(); i++) {
				cout << list_linked.GetData(i) << " ";
				if (i != 0 && i % 10 == 0)
					cout << endl;
			}
			break;
		case 9:
			return 0;
		default:
			break;
		}
	}
}