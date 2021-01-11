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
	ArrayList();//����
	int LDelete_index(int index); //�ε����� ����
	int LDelete_Data(T data);//�����ͷ� ����
	int LNumOfData() { return numOfData; }//������ ���� ���ϱ�
	int LGetMax() { return list_len; }//�ִ� ũ�� ���ϱ�
	int LInsert(T data, int index);//������ �߰�(���ϴ� �ε�����)
	int LInsertAuto(T data);//������ �߰�(�ڵ�)
	void LResize();//������¡
	T LGetData(int index) { return arr[index]; }//������ ����
	int LGetIndex(T data);//�ε��� ã�� ����
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