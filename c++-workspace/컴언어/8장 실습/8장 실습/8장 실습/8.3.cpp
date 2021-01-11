#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity; // ���� �迭 ũ��
	int *mem; // ���� �迭 ������ ���� ������
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};
class MyQueue:public BaseArray {
	int head = 0, tail = -1;
	int size = 0;
public:
	MyQueue(int x) :BaseArray(x){}
	void enqueue(int n) {
		if (size == capacity())
			return;
		size++;
		put(head++, n);
		head = head % capacity();
	}
	int length() {
		return size;
	}
	int capacity() {
		return getCapacity();
	}
	int dequeue() {
		if (size == 0)
			return -1;
		size--;
		tail++;
		tail %= capacity();
		return get(tail);
	}
};
int main() {
	MyQueue mQ(5);
	int n;
		cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
		for (int i = 0; i < 5; i++) {
			cin >> n;
			mQ.enqueue(n); // ť�� ����
		}
		cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
		cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
		while (mQ.length() != 0) {
			cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
		}
		cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;

	mQ.enqueue(3);
	mQ.enqueue(4);
	cout << mQ.dequeue();
	
}
