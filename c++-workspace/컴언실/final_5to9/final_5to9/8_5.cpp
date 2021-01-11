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
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' ';
	}
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;

	MyStack mStack(100);
	int m;
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++)
	{
		cin >> m;
		mStack.push(m);
	}
	cout << "���ÿ뷮:" << mStack.capacity() << ", ����ũ��:" << mStack.length() << endl;
	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> ";
	while (mStack.length() != 0)
	{
		cout << mStack.pop() << ' ';
	}
	cout << endl << "������ ���� ũ��: " << mStack.length() << endl;
}