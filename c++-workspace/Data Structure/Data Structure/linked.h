#ifndef  LINKED_H
#define LINKED_H
#define NULL 0
template <class T>
class Node {
	T data;
	int index;
	Node<T>* next=NULL;
public:
	int getIndex() { return index; }
	Node* getNext() { return next; }
	T getData() { return data; }
	Node* setNext(Node* newNext) { next = newNext; return next; }
	int setIndex(int newIndex) { index = newIndex; return index; }
	T setData(T newData) { data = newData; return data; }
};
template<class T>
class LinkedList {
	Node<T>* First;
	Node<T>* tmp;
	Node<T>* ptmp;
	Node<T>* Last;
	int numOfData;
public:
	LinkedList();
	int GetNumOfData() { return numOfData; }//리스트 길이 구하기
	int Insert(T data, int index);//데이터 삽입
	int InsertAuto(T data);//데이터 삽입 (인덱스 지정X)
	int DeleteData(T data);//데이터 탐색 후 삭제
	int DeleteIndex(int index);//선택한 인덱스 값 삭제
	T GetData(int index);//인덱스 값 리턴
	int GetIndex(T data);//데이터 인덱스 리턴
};
template <class T>
LinkedList<T>::LinkedList() {
	First = new Node<T>;
	numOfData = 0;
	Last = First;
}
template <class T>
int LinkedList<T>::Insert(T data, int index) {
	if (index > numOfData || index < 0) {
		return -1;
	}
	if (numOfData == 0) {
		First->setData(data);
		First->setIndex(0);
		First->setNext(NULL);
		numOfData++;
		return 0;
	}
	if (index == 0)
	{
		ptmp = new Node<T>;
		ptmp->setData(data);
		ptmp->setIndex(0);
		ptmp->setNext(First);
		First = ptmp;
		while (ptmp->getNext() != NULL) {
			ptmp = ptmp->getNext();
			ptmp->setIndex(ptmp->getIndex() + 1);
		}
		numOfData++;
		return 0;
	}
	if (index == numOfData) {
		InsertAuto(data);
		return 0;
	}
	tmp = First;
	while (tmp->getNext()->getIndex() != index) {
		tmp = tmp->getNext();
	}
	ptmp = new Node<T>;
	ptmp->setNext(tmp->getNext());
	ptmp->setData(data);
	ptmp->setIndex(index);
	tmp->setNext(ptmp);
	while (ptmp->getNext() != NULL) {
		ptmp=ptmp->getNext();
		ptmp->setIndex(ptmp->getIndex() + 1);
	}
	if (index == numOfData)
		Last = ptmp;
	numOfData++;
	return 0;
}
template <class T>
int LinkedList<T>::InsertAuto(T data) {
	if (numOfData == 0) {
		First->setData(data);
		First->setIndex(0);
		First->setNext(NULL);
		numOfData++;
		return 0;
	}
	ptmp = new Node<T>;
	Last->setNext(ptmp);
	ptmp->setData(data);
	ptmp->setIndex(numOfData);
	numOfData++;
	Last = ptmp;
	return 0;
}
template <class T>
int LinkedList<T>::DeleteData(T data) {
	DeleteIndex(GetIndex(data));
	return 0;
}
template <class T>
int LinkedList<T>::DeleteIndex(int index) {
	if (index >= numOfData || index < 0)
		return -1;
	ptmp = First;
	if (numOfData == 1 && index == 0) {
		delete ptmp;
		First = new Node<T>;
		Last = First;
		numOfData = 0;
		return 0;
	}
	if (index == 0) {
		First = First->getNext();
		delete ptmp;
		numOfData--;
		ptmp = First;
		ptmp->setIndex(ptmp->getIndex() - 1);
		while (ptmp->getNext() != NULL) {
			ptmp = ptmp->getNext();
			ptmp->setIndex(ptmp->getIndex() - 1);
		}
		return 0;
	}
	while (ptmp->getIndex() != index - 1) {
		ptmp = ptmp->getNext();
	}
	tmp = ptmp->getNext();
	ptmp->setNext(tmp->getNext());
	delete tmp;
	if (ptmp->getNext() == NULL)
		Last = ptmp;
	while (ptmp->getNext() != NULL) {
		ptmp = ptmp->getNext();
		ptmp->setIndex(ptmp->getIndex() - 1);
	}
	numOfData--;
	return 0;
}
template <class T>
T LinkedList<T>::GetData(int index) {
	ptmp = First;
	while (ptmp->getIndex() != index) {
		ptmp = ptmp->getNext();
	}
	return ptmp->getData();
}
template <class T>
int LinkedList<T>::GetIndex(T data) {
	ptmp = First;
	while (ptmp->getNext() != NULL) {
		if (ptmp->getData() == data)
			break;
		ptmp = ptmp->getNext();
	}
	if (ptmp->getData() == data)
		return ptmp->getIndex();
	if (ptmp->getNext() == NULL)
		return -1;
	return ptmp->getIndex();
}
#endif // ! LINKED_H
