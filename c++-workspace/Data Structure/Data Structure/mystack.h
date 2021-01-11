#ifndef  MYSTACK_H
#include <iostream>
using namespace std;
#define MYSTACK_H
#define NULL 0
template <class T>
class Node {
	T data;
	int index;
	Node<T>* next = NULL;
public:
	int getIndex() { return index; }
	Node* getNext() { return next; }
	T getData() { return data; }
	Node* setNext(Node* newNext) { next = newNext; return next; }
	int setIndex(int newIndex) { index = newIndex; return index; }
	T setData(T newData) { data = newData; return data; }
};
template <class T>
class Stack {
	Node<T>* ntop;
	Node<T>* ndata;
	int isize;
public:
	Stack() {
		isize = 0;
		ntop = new Node<T>;
		ntop->setIndex(isize);
	}
	T top() { return ntop->getData(); }
	bool empty() { return isize == 0 ? true : false; }
	int size() { return isize; }
	int pop() { ndata = ntop->getNext(); delete ntop; ntop = ndata; isize--; return 0; }
	void push(T data);
	void print();
};
template <class T>
void Stack<T>::push(T data) {
	if (isize == 0) {
		ntop->setData(data);
		isize++;
		return;
	}
	ndata = new Node<T>;
	ndata->setNext(ntop);
	ndata->setIndex(isize);
	ndata->setData(data);
	ntop = ndata;
	isize++;
	return;
}
template <class T>
void Stack<T>::print() {
	ndata = ntop;
	do{
		cout << ndata->getData() << " ";
	}while ((ndata = ndata->getNext()) != NULL);
	cout << endl;
}
#endif // ! LINKED_H
