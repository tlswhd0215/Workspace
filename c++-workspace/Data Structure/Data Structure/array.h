#include <cstring>
using namespace std;
#ifndef ARRAY_H
#define ARRAY_H
template<class T>
class ArrayList {
	int list_len = 5;
	T* arr;
	int numOfData;
public:
	ArrayList();//선언
	int LDelete_index(int index); //인덱스로 삭제
	int LDelete_Data(T data);//데이터로 삭제
	int LNumOfData() { return numOfData; }//데이터 개수 구하기
	int LGetMax() { return list_len; }//최대 크기 구하기
	int LInsert(T data, int index);//데이터 추가(원하는 인덱스에)
	int LInsertAuto(T data);//데이터 추가(자동)
	void LResize();//리사이징
	T LGetData(int index) { return arr[index]; }//데이터 리턴
	int LGetIndex(T data);//인덱스 찾아 리턴
	~ArrayList() { delete arr; }
};
template <class T>
ArrayList<T>::ArrayList() {
	numOfData = 0;
	arr = new T[list_len];
}
template <class T>
int ArrayList<T>::LInsert(T data, int index) {
	if (index > numOfData || index < 0)
		return -1;
	if (numOfData == list_len)
		LResize();
		for (int i = numOfData; i >index; i--) {
			arr[i] = arr[i - 1];
		}
	arr[index] = data;
	numOfData++;
	return index;
}
template <class T>
int ArrayList<T>::LInsertAuto(T data) {
	if (numOfData == list_len)
		LResize();
	arr[numOfData] = data;
	numOfData++;
	return numOfData-1;
}
template <class T>
int ArrayList<T>::LDelete_index(int index) {
	if (index >= numOfData||index<0)
		return -1;
	for (int i = index+1; i < numOfData; i++) {
		arr[i - 1] = arr[i];
	}
	numOfData--;
	return index;
}
template <class T>
int ArrayList<T>::LDelete_Data(T data) {
	return LDelete_index(LGetIndex(data));
}
template <class T>
void ArrayList<T>::LResize() {
	T* tmp = new T[list_len * 3 / 2];
	memcpy(tmp, arr, list_len * sizeof(T));
	delete arr;
	list_len = list_len * 3 / 2;
	arr = tmp;
}
template <class T>
int ArrayList<T>::LGetIndex(T data) {
	for (int i = 0; i < numOfData; i++) {
		if (arr[i] == data)return i;
	}
	return -1;
}
#endif