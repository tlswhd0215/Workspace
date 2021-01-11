#include "array.h"
#include <iostream>
using namespace std;

int main() {
	ArrayList<int> list_Array;
	int menu;
	int tempData;
	int tempIndex;
	while (1) {
		cout <<endl<< "############################### 메뉴 선택 ###############################"<<endl;
		cout << "1번 : 데이터 자동 삽입 || 2번 : 인덱스 선택 삽입 || 3번 : 인덱스 선택 삭제 " << endl;
		cout << "4번 : 데이터 검색 삭제 || 5번 : 데이터 검색 || 6번 : 선택 인덱스 탐색" << endl;
		cout << "7번 : 데이터 개수 구하기 || 8번 : 리스트 최대 크기 구하기 || 9번 전체 출력하기" << endl;
		cout << "0번 : 종료 || 메뉴를 선택하시오 <-";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "값 입력 <- ";
			cin >> tempData;
			list_Array.LInsertAuto(tempData);
			break;
		case 2:
			cout << "값 입력 <- ";
			cin >> tempData;
			cout << "인덱스 입력 <- ";
			cin >> tempIndex;
			if(list_Array.LInsert(tempData,tempIndex)==-1)
				cout << "실패!" << endl;
			break;
		case 3:
			cout << "삭제할 인덱스 입력 <- ";
			cin >> tempIndex;
			if (list_Array.LDelete_index(tempIndex) == -1)
				cout << "실패!" << endl;
			break;
		case 4:
			cout << "값 입력 <- ";
			cin >> tempData;
			if(list_Array.LDelete_Data(tempData)==-1)
				cout << "실패!" << endl;
			break;
		case 5:
			cout << "값 입력 <- ";
			cin >> tempData;
			tempIndex = list_Array.LGetIndex(tempData);
			if (tempIndex == -1)
				cout << "실패!" << endl;
			else
				cout << tempIndex << "에 존재합니다!" << endl;
			break;
		case 6:
			cout << "인덱스 입력 <- ";
			cin >> tempIndex;
			tempData = list_Array.LGetData(tempIndex);
			cout << tempIndex << "의 값은 " << tempData << "입니다!" << endl;
			break;
		case 7:
			cout << "데이터의 개수는 " << list_Array.LNumOfData() << "개 입니다!" << endl;
			break;
		case 8:
			cout << "리스트의 최대 길이는 " << list_Array.LGetMax() << "입니다!" << endl;
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