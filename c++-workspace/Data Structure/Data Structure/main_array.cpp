#include "array.h"
#include <iostream>
using namespace std;

int main() {
	ArrayList<int> list_Array;
	int menu;
	int tempData;
	int tempIndex;
	while (1) {
		cout <<endl<< "############################### �޴� ���� ###############################"<<endl;
		cout << "1�� : ������ �ڵ� ���� || 2�� : �ε��� ���� ���� || 3�� : �ε��� ���� ���� " << endl;
		cout << "4�� : ������ �˻� ���� || 5�� : ������ �˻� || 6�� : ���� �ε��� Ž��" << endl;
		cout << "7�� : ������ ���� ���ϱ� || 8�� : ����Ʈ �ִ� ũ�� ���ϱ� || 9�� ��ü ����ϱ�" << endl;
		cout << "0�� : ���� || �޴��� �����Ͻÿ� <-";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "�� �Է� <- ";
			cin >> tempData;
			list_Array.LInsertAuto(tempData);
			break;
		case 2:
			cout << "�� �Է� <- ";
			cin >> tempData;
			cout << "�ε��� �Է� <- ";
			cin >> tempIndex;
			if(list_Array.LInsert(tempData,tempIndex)==-1)
				cout << "����!" << endl;
			break;
		case 3:
			cout << "������ �ε��� �Է� <- ";
			cin >> tempIndex;
			if (list_Array.LDelete_index(tempIndex) == -1)
				cout << "����!" << endl;
			break;
		case 4:
			cout << "�� �Է� <- ";
			cin >> tempData;
			if(list_Array.LDelete_Data(tempData)==-1)
				cout << "����!" << endl;
			break;
		case 5:
			cout << "�� �Է� <- ";
			cin >> tempData;
			tempIndex = list_Array.LGetIndex(tempData);
			if (tempIndex == -1)
				cout << "����!" << endl;
			else
				cout << tempIndex << "�� �����մϴ�!" << endl;
			break;
		case 6:
			cout << "�ε��� �Է� <- ";
			cin >> tempIndex;
			tempData = list_Array.LGetData(tempIndex);
			cout << tempIndex << "�� ���� " << tempData << "�Դϴ�!" << endl;
			break;
		case 7:
			cout << "�������� ������ " << list_Array.LNumOfData() << "�� �Դϴ�!" << endl;
			break;
		case 8:
			cout << "����Ʈ�� �ִ� ���̴� " << list_Array.LGetMax() << "�Դϴ�!" << endl;
			break;
		case 9:
			for (int i = 0; i < list_Array.LNumOfData(); i++) {
				cout << list_Array.LGetData(i) << " ";
				if (i != 0 && i % 10 == 0)
					cout << endl;
			}
			break;
		case 0:
			return 0;
		default:
			break;
		}
	}
}