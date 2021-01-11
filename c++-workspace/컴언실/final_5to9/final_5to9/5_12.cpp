#include <iostream>
using namespace std;

class Dept {
	int size;
	int *scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	/*Dept(const Dept& dept) {
		size = dept.size;
		scores = new int[size];
		for (int i = 0; i < size; i++)
		{
			scores[i] = dept.scores[i];
		}
	}*/
	~Dept() {
		delete[] scores;
	}
	int getSize() { return size; }
	void read() {
		for(int i=0;i<size;i++)
		{
			cin >> scores[i];
		}
	}
	bool isOver60(int index) {
		if (scores[index] > 60)
			return true;
		else return false;
	}
};
int countPass(Dept& dept) {
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}
int main() {
	Dept com(10);
	com.read();
	int n = countPass(com);
	cout << "60�� �̻��� " << n << "��";
}