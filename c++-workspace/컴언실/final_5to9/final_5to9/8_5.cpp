#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity;
	int*mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};
class MyQue:public BaseArray {
	int head=0;
	int tail=-1;
	int size = 0;
public:
	MyQue(int n):BaseArray(n){}
	void enqueue(int n) {
		put(head, n);
		size++;
		head++;
	}
	int capacity() { return getCapacity(); }
	int length() { return size; }
	int dequeue() {
		tail++;
		size--;
		return get(tail);
	}
};
class MyStack :public BaseArray{
	int size = 0;
	int tos = 0;
public:
	MyStack(int n) :BaseArray(n) {}
	void push(int n) {
		put(tos, n);
		size++;
		tos++;
	}
	int pop() {
		tos--;
		size--;
		return get(tos);
	}
	int length() { return size; }
	int capacity() { return getCapacity(); }
};
int main() {
	MyQue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' ';
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;

	MyStack mStack(100);
	int m;
	cout << "스택에 삽일할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++)
	{
		cin >> m;
		mStack.push(m);
	}
	cout << "스택용량:" << mStack.capacity() << ", 스택크기:" << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다>> ";
	while (mStack.length() != 0)
	{
		cout << mStack.pop() << ' ';
	}
	cout << endl << "스택의 현재 크기: " << mStack.length() << endl;
}